#pragma once
#include <string>
#include <unordered_map>
#include <SDL.h>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
struct ConfigDeSerializer
{
private:
	static const string INPUT_LINE_DELIMITER;
	static void Serialize(string* path, string* content);
	static vector<string> Deserialize(string* path);
public:
	static void SerializeInputConfig(unordered_map<SDL_Keycode, SDL_Keycode>* keybinds, string* path);
	static unordered_map<SDL_Keycode, SDL_Keycode> DeserializeInputConfig(string* path);
};

