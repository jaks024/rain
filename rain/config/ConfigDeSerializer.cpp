#include <rain/config/ConfigDeSerializer.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <format>
#include <vector>
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::format;
using std::vector;

const string ConfigDeSerializer::INPUT_LINE_DELIMITER = ": ";

void ConfigDeSerializer::Serialize(string* const path, string* const content)
{
	ofstream file(*path);
	if (file.is_open())
	{
		file << content;
		file.close();
		return;
	}
	printf(("unable to open " + *path + "\n").c_str());
}

 vector<string>* ConfigDeSerializer::Deserialize(string* const path)
{
	ifstream file(*path);
	string line;
	vector<string> lines;
	if (file.is_open()) {
		
		while (std::getline(file, line))
		{
			lines.push_back(line);
		}
		file.close();
		return &lines;
	}
	printf(("unable to open " + *path + "\n").c_str());
	return &lines;
}

void ConfigDeSerializer::SerializeInputConfig(
	unordered_map<SDL_Keycode, SDL_Keycode>* const keybinds, string* const path)
{
	string content = "";
	for (auto& [key, value] : *keybinds)
	{
		string from = SDL_GetKeyName(key);
		string to = SDL_GetKeyName(value);
		content.append(format("{}: {}\n", from, to));
	}
	Serialize(path, &content);
}

unordered_map<SDL_Keycode, SDL_Keycode>* ConfigDeSerializer::DeserializeInputConfig(string* const path)
{
	unordered_map<SDL_Keycode, SDL_Keycode> keybinds;
	vector<string>* content = Deserialize(path);
	for (auto& line : *content)
	{
		int delimiterIndex = line.find(INPUT_LINE_DELIMITER);
		string key = line.substr(0, delimiterIndex);
		string value = line.substr(
			delimiterIndex + INPUT_LINE_DELIMITER.length(), 
			line.length() - 1);
		SDL_Keycode keyKey = SDL_GetKeyFromName(key.c_str());
		SDL_Keycode valueKey = SDL_GetKeyFromName(key.c_str());
		keybinds.insert({ keyKey, valueKey });
	}
	return &keybinds;
}
