#pragma once
#include <rain/assets/Asset.hpp>
#include <SDL.h>
#include <memory>
struct TextureAsset : public Asset
{
	SDL_Texture* texture;

	TextureAsset(int id, string name, AssetType type, SDL_Texture* texture)
		: Asset(id, name, type), texture{ texture } {};

	virtual ~TextureAsset(void)
	{
		SDL_DestroyTexture(texture);
	}
};

