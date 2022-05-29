#pragma once
#include <rain/events/EventArgs.hpp>
#include <rain/pixel/objects/ActiveAreas.hpp>
#include <memory>
struct ActiveAreasFoundEventArgs
{
	std::shared_ptr<ActiveAreas> newFoundAreas;

	ActiveAreasFoundEventArgs(std::shared_ptr<ActiveAreas> newAreas)
		: newFoundAreas{ newAreas } {}
	virtual ~ActiveAreasFoundEventArgs(void) = default;
};

