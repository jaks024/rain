#include <rain/input/InputKeybindManager.hpp>
#include <rain/config/ConfigDeSerializer.hpp>

void InputKeybindManager::Bind(const SDL_Keycode key, const SDL_Keycode to)
{
	keybindMap.insert({ key, to });
}

void InputKeybindManager::Remove(const SDL_Keycode key)
{
	keybindMap.erase(key);
}

void InputKeybindManager::Load(string* const path)
{
	keybindMap = ConfigDeSerializer::DeserializeInputConfig(path);
}

void InputKeybindManager::Save(string* const path)
{
	ConfigDeSerializer::SerializeInputConfig(&keybindMap, path);
}
