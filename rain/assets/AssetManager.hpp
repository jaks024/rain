#pragma once
#include <unordered_map>
#include <rain/assets/Asset.hpp>
#include <memory>
#include <rain/assets/TextureAsset.hpp>
using std::unordered_map;
using std::shared_ptr;

class AssetManager
{
	SDL_Renderer* renderer;
	string assetRootPath;
	int idCount;
	unordered_map<int, shared_ptr<Asset>> assetMap;

	int GetNewId(void);
	string GetJointFullPath(string relativePath);

public:
	AssetManager(SDL_Renderer* renderer, string assetRootPath);
	virtual ~AssetManager(void) = default;

	int Create(string relativePath, string name, AssetType type);
	void Destroy(int id);

	template<class T>
	shared_ptr<T> Get(int id)
	{
		auto result = assetMap.find(id);
		if (result == assetMap.end())
		{
			return nullptr;
		}
		
		auto genericAsset = result->second;
		switch (genericAsset->type)
		{
		case AssetType::TEXTURE:
		{
			if (typeid(T) == typeid(TextureAsset))
			{
				return std::dynamic_pointer_cast<TextureAsset>(genericAsset);
			}
		}
		default:
			break;
		}
		return nullptr;
	}
};

