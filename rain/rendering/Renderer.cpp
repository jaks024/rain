#include <rain/rendering/Renderer.hpp>

Renderer::Renderer(SDL_Window* window, const int screenWidth, const int screenHeight)
{
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created: %s", SDL_GetError());
		return;
	}

	SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
}

Renderer::~Renderer(void)
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::ProcessRenderQueue(shared_ptr<RenderLayerManager> renderLayerManager, shared_ptr<AssetManager> assetManager)
{
	auto layers = renderLayerManager->GetAll();
	for (auto const& [index, layer] : *layers)
	{
		for (auto& [id, obj] : layer->objInLayer)
		{
			SDL_Rect dest;
			dest.w = 1 * obj->scale.x;
			dest.h = 1 * obj->scale.y;
			dest.x = obj->position.x;
			dest.y = obj->position.y;

			auto textureAsset = assetManager->Get<TextureAsset>(obj->assetId);
			if (textureAsset != nullptr)
			{
				SDL_SetTextureBlendMode(textureAsset->texture, SDL_BlendMode::SDL_BLENDMODE_ADD);
				SDL_SetTextureColorMod(textureAsset->texture, obj->color.r, obj->color.g, obj->color.b);
				SDL_SetTextureAlphaMod(textureAsset->texture, obj->color.a);
				SDL_RenderCopy(renderer, textureAsset->texture, NULL, &dest);
			}
		}
	}
}


void Renderer::Render(shared_ptr<RenderLayerManager> renderLayerManager, shared_ptr<AssetManager> assetManager)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderClear(renderer);

	ProcessRenderQueue(renderLayerManager, assetManager);

	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::GetRenderer(void)
{
	return renderer;
}
