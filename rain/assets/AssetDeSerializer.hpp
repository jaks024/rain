#pragma once
#include <rain/assets/TextureAsset.hpp>
using std::shared_ptr;
struct AssetDeSerializer
{
	static shared_ptr<TextureAsset> LoadTextureAsTextureAsset(
		SDL_Renderer* renderer, 
		const string& path,
		int id,
		string name);
};

