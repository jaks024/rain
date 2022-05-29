#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/pixel/objects/PixelType.hpp>
#include <rain/pixel/objects/PixelClassification.hpp>
#include <SDL.h>

struct Pixel
{
	bool isEnabled;
	Vector2<int> position;
	SDL_Color color;
	float velocity;
	float temperature;
	PixelType type;
	PixelClassification classification;

	Pixel(void) : 
		isEnabled{true}, 
		position{Vector2<int>::Zero()},
		color{SDL_Color()},
		velocity{ 0 },
		temperature{0},
		type{PixelType::BLANK},
		classification{ PixelClassification::STATIC } {};

	Pixel(Vector2<int> position, SDL_Color color, PixelType type, PixelClassification classification) :
		isEnabled{ true },
		position{ position },
		color{ color },
		velocity{ 0 },
		temperature{ 0 },
		type{ type },
		classification{ classification } {};

	virtual ~Pixel(void) = default;
};

