#include <rain/pixel/ChunkObserver.hpp>
#include <rain/events/ActiveAreasFoundEventArgs.hpp>


void ChunkObserver::NotifyActiveAreasFound(ActiveAreasFoundEventArgs args)
{
	activeAreasFoundEvent.Invoke(args);
}

void ChunkObserver::OnDataSetEventHandler(ChunkDataChangedEventArgs args)
{
	auto newActiveAreas = ActiveAreasCreator::Create(args);
	if (newActiveAreas == nullptr) 
	{
		return;
	}
	ActiveAreasFoundEventArgs notifyActiveAreasFoundArgs = ActiveAreasFoundEventArgs(newActiveAreas);
	NotifyActiveAreasFound(notifyActiveAreasFoundArgs);
}

void ChunkObserver::SubscribeToChunkDataChangedEvent(shared_ptr<ActiveAreasManager> manager)
{
	activeAreasFoundEvent += std::bind(&ActiveAreasManager::OnActiveAreasFoundEventHandler, manager, std::placeholders::_1);
}
