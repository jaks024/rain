#include <rain/assets/AssetDeSerializer.hpp>
#include <SDL_image.h>
using std::make_shared;

shared_ptr<TextureAsset> AssetDeSerializer::LoadTextureAsTextureAsset(
	SDL_Renderer* renderer,
	const string& path,
	int id,
	string name)
{
	SDL_Texture* newTexture = nullptr;

	newTexture = IMG_LoadTexture(renderer, path.c_str());
	shared_ptr<TextureAsset> newTextureAsset = make_shared<TextureAsset>(
		id, 
		name, 
		AssetType::TEXTURE, 
		newTexture);

	printf("Loaded %s\n", path.c_str());
	
	return newTextureAsset;
}
