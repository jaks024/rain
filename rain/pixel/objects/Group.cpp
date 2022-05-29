#include <rain/pixel/objects/Group.hpp>

Group::Group(int id, Vector2<int> position, vector<shared_ptr<Chunk>> chunks)
	: id{ id }, position{ position }, chunks{ chunks } {}

void Group::SetPosition(Vector2<int> newPosition)
{
	Vector2<int> oldPosition = position;
	position = newPosition;
	for (auto& chunk : chunks)
	{
		Vector2<int> chunkPosition = chunk->GetPosition();
		int xOffset = chunkPosition.x - oldPosition.x;
		int yOffset = chunkPosition.y - oldPosition.y;
		chunkPosition.Set(xOffset + position.x, yOffset + position.y);
	}
}

Vector2<int> Group::GetPosition(void)
{
	return position;
}

vector<shared_ptr<Chunk>>* Group::GetChunks(void)
{
	return &chunks;
}
