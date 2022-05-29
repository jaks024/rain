#pragma once
#include <rain/events/EventArgs.hpp>
#include <vector>
#include <rain/pixel/objects/Pixel.hpp>
using std::vector;

struct ChunkDataChangedEventArgs : public EventArgs
{
	int chunkId;
	vector<vector<Pixel>>* oldData;
	vector<vector<Pixel>>* newData;

	ChunkDataChangedEventArgs(
		int chunkId,
		vector<vector<Pixel>>* oldData,
		vector<vector<Pixel>>* newData) : 
		chunkId{ chunkId },  
		oldData { oldData }, 
		newData{ newData } {}
	virtual ~ChunkDataChangedEventArgs(void) = default;
};

