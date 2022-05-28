#include <rain/assets/AssetManager.hpp>
#include <rain/assets/AssetDeSerializer.hpp>
#include <format>

AssetManager::AssetManager(SDL_Renderer* renderer, string assetRootPath)
	: renderer{ renderer }, assetRootPath{ assetRootPath }, idCount{ 0 } { }

int AssetManager::GetNewId(void)
{
	int newId = idCount;
	++idCount;
	return newId;
}

string AssetManager::GetJointFullPath(string relativePath)
{
	return std::format("{}\\{}", assetRootPath, relativePath);
}

int AssetManager::Create(string relativePath, string name, AssetType type)
{
	int id = GetNewId();
	string fullPath = GetJointFullPath(relativePath);
	switch (type)
	{
	case AssetType::TEXTURE:
	{
		auto newTextureAsset = AssetDeSerializer::LoadTextureAsTextureAsset(renderer, fullPath, id, name);
		assetMap.insert({ id,  newTextureAsset });
		break;
	}
	case AssetType::FONT:
		break;
	case AssetType::PREFAB:
		break;
	case AssetType::AUDIO:
		break;
	case AssetType::ANIMATION:
		break;
	default:
		break;
	}
	return id;
}

void AssetManager::Destroy(int id)
{
	auto result = assetMap.find(id);
	if (result != assetMap.end())
	{
		assetMap.erase(result);
	}
}
