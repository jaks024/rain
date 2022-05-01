#pragma once
#include <rain/events/EventArgs.hpp>
struct EntityComponentEditorEventArgs : public EventArgs
{
	int* componentSourceId;
	bool isCreate;

	EntityComponentEditorEventArgs(int* componentSourceId, bool isCreate) : 
		componentSourceId{ componentSourceId }, isCreate{ isCreate } {}
	virtual ~EntityComponentEditorEventArgs(void) = default;
};

