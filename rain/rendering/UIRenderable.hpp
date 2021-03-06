#pragma once
#include <rain/rendering/Renderable.hpp>
#include <SDL.h>
#include <vector>
using std::vector;

struct UIRenderable : public Renderable
{
	SDL_Color color;
	vector<UIRenderable> children;
};

