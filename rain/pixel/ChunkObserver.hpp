#pragma once
#include <rain/events/EventHandler.hpp>
#include <rain/events/ChunkDataChangedEventArgs.hpp>
#include <rain/pixel/ActiveAreasCreator.hpp>
#include <rain/pixel/ActiveAreasManager.hpp>
class ChunkObserver
{
	EventHandler<ActiveAreasFoundEventArgs> activeAreasFoundEvent;
	void NotifyActiveAreasFound(ActiveAreasFoundEventArgs args);

public:
	void OnDataSetEventHandler(ChunkDataChangedEventArgs args);
	void SubscribeToChunkDataChangedEvent(shared_ptr<ActiveAreasManager> manager);
};

