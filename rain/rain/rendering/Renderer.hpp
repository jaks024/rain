#pragma once
#include <SDL.h>
#include <queue>
#include <rain/rendering/UIRenderable.hpp>
#include <rain/rendering/GraphicsRenderable.hpp>
using std::priority_queue;

class Renderer
{
private:
	SDL_Renderer* renderer;
	priority_queue<UIRenderable> uiRenderQueue;
	priority_queue<GraphicsRenderable> graphicsRenderQueue;

	void RenderUI(void);
	void RenderGraphics(void);

public:
	Renderer(SDL_Window* window, int screenWidth, int screenHeight);
	~Renderer(void);

	void AddToUIQueue(UIRenderable obj);
	void AddToGraphicsQueue(GraphicsRenderable graphics);
	UIRenderable RemoveFromUIQueue(int id);
	GraphicsRenderable RemoveFromGraphicsQueue(int id);
	void Render(void);
};

