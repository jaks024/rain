#pragma once
#include <memory>
#include <rain/pixel/objects/ActiveAreas.hpp>
#include <rain/events/ChunkDataChangedEventArgs.hpp>
using std::shared_ptr;

struct ActiveAreasCreator
{
	static shared_ptr<ActiveAreas> Create(ChunkDataChangedEventArgs args);
};

