#include <rain/input/InputKeybindManager.hpp>

void InputKeybindManager::Bind(const SDL_Keycode key, const SDL_Keycode to)
{
	keybindMap.insert({ key, to });
}

void InputKeybindManager::Remove(const SDL_Keycode key)
{
	keybindMap.erase(key);
}

void InputKeybindManager::Load(const string path)
{
}

void InputKeybindManager::Save(const string path)
{
}
