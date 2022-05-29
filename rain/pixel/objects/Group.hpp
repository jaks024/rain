#pragma once
#include <rain/pixel/objects/Chunk.hpp>
class Group
{
	int id;
	Vector2<int> position;
	vector<shared_ptr<Chunk>> chunks;

public:
	Group(int id, Vector2<int> position, vector<shared_ptr<Chunk>> chunks);
	virtual ~Group(void) = default;

	void SetPosition(Vector2<int> newPosition);
	Vector2<int> GetPosition(void);
	vector<shared_ptr<Chunk>>* GetChunks(void);
};

