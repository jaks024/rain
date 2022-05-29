#pragma once
#include <rain/events/ActiveAreasFoundEventArgs.hpp>
#include <unordered_map>
#include <memory>
using std::unordered_map;
using std::shared_ptr;

class ActiveAreasManager
{
	unordered_map<int, shared_ptr<ActiveAreas>> chunkActiveAreas;

public:
	shared_ptr<ActiveAreas> Get(int id);
	void Add(shared_ptr<ActiveAreas> newAreas);
	void Update(int id, shared_ptr<ActiveAreas> updatedAreas);
	void Remove(int id);	
	void OnActiveAreasFoundEventHandler(ActiveAreasFoundEventArgs args);
};

