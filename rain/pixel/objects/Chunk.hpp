#pragma once
#include <rain/pixel/objects/Pixel.hpp>
#include <vector>
#include <rain/events/EventHandler.hpp>
#include <rain/events/ChunkDataChangedEventArgs.hpp>
#include <rain/pixel/ChunkObserver.hpp>
using std::vector;

class Chunk
{
	const Vector2<int> up = { 0, -1 };	// x, y
	const Vector2<int> down = { 0, 1 };
	const Vector2<int> left = { -1, 0 };
	const Vector2<int> right = { 1, 0 };
	const Vector2<int> upLeft = { -1, -1 };
	const Vector2<int> upRight = { 1, -1 };
	const Vector2<int> downLeft = { -1, 1 };
	const Vector2<int> downRight = { 1, 1 };

	int id;
	Vector2<int> position;
	int pixelWidth;
	int pixelHeight;
	vector<vector<Pixel>> pixelGrid;
	EventHandler<ChunkDataChangedEventArgs> OnSetDataEvent;

	void NotifyOnSetDataEvent(vector<vector<Pixel>>* newData);
	bool RandomBool(void);
	void SwapPixel(size_t fy, size_t fx, size_t ty, size_t tx);
	bool IsInRange(size_t y, size_t x);
	bool SimulateGrains(size_t y, size_t x);
	bool SimulateLiquid(size_t y, size_t x);
	bool SimulateGas(size_t y, size_t);

public:
	Chunk(int id, Vector2<int> position);
	virtual ~Chunk(void) = default;
	
	void SubscribeObserverToOnSetDataEvent(shared_ptr<ChunkObserver> observer);
	void SetData(vector<vector<Pixel>> newData, int pixelWidth, int pixelHeight);
	vector<vector<Pixel>>* GetData(void);
	void SetPosition(Vector2<int> newPosition);
	Vector2<int> GetPosition(void);
	int GetId(void);
	void Simulate(void);
};

