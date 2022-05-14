#pragma once
#include <unordered_map>
#include <SDL.h>
#include <memory>
#include <functional>
#include <rain/events/EventHandler.hpp>
#include <rain/events/InputEventArgs.hpp>
#include <rain/input/InputKeybindManager.hpp>
using std::unordered_map;
using std::shared_ptr;
using std::function;
class InputEventManager
{
private:
	unordered_map<SDL_Keycode, shared_ptr<EventHandler<InputEventArgs>>> inputEvents;
	shared_ptr<InputKeybindManager> keybindManager;
	shared_ptr<EventHandler<InputEventArgs>> GetEventHanlder(SDL_Keycode key);

public:
	InputEventManager(shared_ptr<InputKeybindManager> keybindManager);
	virtual ~InputEventManager(void) = default;
	void Subscribe(SDL_Keycode key, function<void(InputEventArgs)> action);
	void Unsubscribe(SDL_Keycode key, function<void(InputEventArgs)> action);
	void Poll(void);
};

