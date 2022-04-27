#include "Renderer.hpp"


Renderer::Renderer(SDL_Window* window, int screenWidth, int screenHeight)
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

void Renderer::AddToUIQueue(UIRenderable obj)
{
}

void Renderer::AddToGraphicsQueue(GraphicsRenderable graphics)
{
}

UIRenderable Renderer::RemoveFromUIQueue(int id)
{
	return UIRenderable();
}

GraphicsRenderable Renderer::RemoveFromGraphicsQueue(int id)
{
	return GraphicsRenderable();
}

void Renderer::RenderUI(void)
{
}

void Renderer::RenderGraphics(void)
{
}

void Renderer::Render(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderClear(renderer);

	RenderGraphics();
	RenderUI();

	SDL_RenderPresent(renderer);
}
