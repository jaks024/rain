#pragma once
#include <rain/pixel/objects/Pixel.hpp>
#include <vector>
#include <rain/events/EventHandler.hpp>
#include <rain/events/ChunkDataChangedEventArgs.hpp>
#include <rain/pixel/ChunkObserver.hpp>
using std::vector;

class Chunk
{
	int id;
	Vector2<int> position;
	int pixelWidth;
	int pixelHeight;
	vector<vector<Pixel>> pixelGrid;
	EventHandler<ChunkDataChangedEventArgs> OnSetDataEvent;

	void NotifyOnSetDataEvent(vector<vector<Pixel>>* newData);

public:
	Chunk(int id, Vector2<int> position, int pixelWidth, int pixelHeight);
	virtual ~Chunk(void) = default;
	
	void SubscribeObserverToOnSetDataEvent(shared_ptr<ChunkObserver> observer);
	void SetData(vector<vector<Pixel>> newData);
	vector<vector<Pixel>>* GetData(void);
	void SetPosition(Vector2<int> newPosition);
	Vector2<int> GetPosition(void);
	int GetId(void);
};

