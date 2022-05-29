#include <rain/pixel/ActiveAreasManager.hpp>

shared_ptr<ActiveAreas> ActiveAreasManager::Get(int id)
{
	auto result = chunkActiveAreas.find(id);
	if (result != chunkActiveAreas.end())
	{
		return result->second;
	}
	return nullptr;
}

void ActiveAreasManager::Add(shared_ptr<ActiveAreas> newAreas)
{
	chunkActiveAreas.insert({ newAreas->chunkId, newAreas });
}

void ActiveAreasManager::Update(int id, shared_ptr<ActiveAreas> updatedAreas)
{
	auto result = chunkActiveAreas.find(id);
	if (result != chunkActiveAreas.end())
	{
		result->second = updatedAreas;
	}
}

void ActiveAreasManager::Remove(int id)
{
	auto areas = Get(id);
	if (areas != nullptr)
	{
		chunkActiveAreas.erase(id);
	}
}

void ActiveAreasManager::OnActiveAreasFoundEventHandler(ActiveAreasFoundEventArgs args)
{
	if (chunkActiveAreas.contains(args.newFoundAreas->chunkId))
	{
		Update(args.newFoundAreas->chunkId, args.newFoundAreas);
	}
	else
	{
		Add(args.newFoundAreas);
	}
}
