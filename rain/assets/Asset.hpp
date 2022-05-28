#pragma once
#include <string>
#include <rain/assets/AssetType.hpp>
using std::string;
struct Asset
{
	int id;
	string name;
	AssetType type;

	Asset(int id, string name, AssetType type)
		: id{ id }, name{ name }, type{ type } {};
	virtual ~Asset(void) = default;
};

