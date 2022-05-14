#include <rain/input/InputEventManager.hpp>

shared_ptr<EventHandler<InputEventArgs>> InputEventManager::GetEventHanlder(SDL_Keycode key)
{
	auto eventHanlderFindIterator = inputEvents.find(key);
	if (eventHanlderFindIterator != inputEvents.end()) 
	{
		return eventHanlderFindIterator->second;
	}
	return NULL;
}

InputEventManager::InputEventManager(shared_ptr<InputKeybindManager> keybindManager)
	: keybindManager{ keybindManager } { }

void InputEventManager::Subscribe(SDL_Keycode key, function<void(InputEventArgs)> action)
{
	auto findResultIterator = inputEvents.find(key);
	if (findResultIterator != inputEvents.end())
	{
		*(findResultIterator->second) += action;
		return;
	}
	
	shared_ptr<EventHandler<InputEventArgs>> keyEventHandler = std::make_shared<EventHandler<InputEventArgs>>();
	*(keyEventHandler) += action;
	inputEvents.insert({ key, keyEventHandler });
}

void InputEventManager::Unsubscribe(SDL_Keycode key, function<void(InputEventArgs)> action)
{
	auto findResultIterator = inputEvents.find(key);
	if (findResultIterator != inputEvents.end())
	{
		*(findResultIterator->second) -= action;
	}
}

void InputEventManager::Poll(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		SDL_Keycode pressedKey = event.key.keysym.sym;
		SDL_Keycode bindedKey = pressedKey;
		keybindManager->Get(pressedKey, &bindedKey);

		shared_ptr<EventHandler<InputEventArgs>> keyEventHandler = GetEventHanlder(bindedKey);
		if (keyEventHandler != NULL)
		{
			keyEventHandler->Invoke(bindedKey);
		}

		// put into SDLEventHandler
		// add SDL_QUIT trigger
		//switch (event.type)
		//{
		//case SDL_QUIT:
		//	OnQuit();
		//	break;
		//default:
		//	break;
		//}
	}
}
