#pragma once
#include <SDL.h>
#include <memory>
#include <rain/rendering/RenderLayerManager.hpp>
#include <rain/assets/AssetManager.hpp>

class Renderer
{
private:
	SDL_Renderer* renderer;
	
	void ProcessRenderQueue(shared_ptr<RenderLayerManager> renderLayerManager, shared_ptr<AssetManager> assetManager);

public:
	Renderer(SDL_Window* window, int screenWidth, int screenHeight);
	~Renderer(void);

	void Render(shared_ptr<RenderLayerManager> renderLayerManager, shared_ptr<AssetManager> assetManager);
	SDL_Renderer* GetRenderer(void);
};

