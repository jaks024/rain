#pragma once
#include <rain/events/EventArgs.hpp>
#include <SDL.h>
struct InputEventArgs : public EventArgs
{
	SDL_Keycode key;
	InputEventArgs(SDL_Keycode key) 
		: key{ key } { }
	InputEventArgs(std::string message, SDL_Keycode key)
		: EventArgs(message), key{key} { }
	~InputEventArgs(void) = default;
};

