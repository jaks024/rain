#pragma once
#include <rain/events/EventArgs.hpp>
#include <rain/utilities/Area.hpp>
#include <vector>
using std::vector;

struct ActiveAreas
{
	int chunkId;
	vector<Area<int>> areas;

	void AddArea(Area<int> area)
	{
		areas.push_back(area);
	}
};

