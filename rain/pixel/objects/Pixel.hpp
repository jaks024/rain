#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/pixel/objects/PixelType.hpp>
#include <rain/pixel/objects/PixelClassification.hpp>
#include <rain/components/Renderable.hpp>
#include <memory>
#include <SDL.h>
using std::shared_ptr;

struct Pixel
{
	bool isEnabled;
	Vector2<int> position;
	SDL_Color color;
	float velocity;
	float temperature;
	PixelType type;
	PixelClassification classification;
	shared_ptr<Renderable> renderable;

	Pixel(void) : 
		isEnabled{true}, 
		position{Vector2<int>::Zero()},
		color{SDL_Color()},
		velocity{ 0 },
		temperature{0},
		type{PixelType::BLANK},
		classification{ PixelClassification::SOLID } {};

	Pixel(Vector2<int> position, SDL_Color color, PixelType type, PixelClassification classification) :
		isEnabled{ true },
		position{ position },
		color{ color },
		velocity{ 0 },
		temperature{ 0 },
		type{ type },
		classification{ classification } {};

	void SetData(Pixel& from);
	void AttachRenderable(shared_ptr<Renderable> newRenderable);
	void UpdateRenderable(void);

	virtual ~Pixel(void) = default;
};

