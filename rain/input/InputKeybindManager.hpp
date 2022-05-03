#pragma once
#include <unordered_map>
#include <SDL.h>
#include <string>
using std::string;
using std::unordered_map;
class InputKeybindManager
{
private:
	unordered_map<SDL_Keycode, SDL_Keycode> keybindMap;

public:
	void Bind(SDL_Keycode key, SDL_Keycode to);
	void Remove(SDL_Keycode key);
	void Load(string path);
	void Save(string path);
};

