#include <rain/pixel/objects/Chunk.hpp>

Chunk::Chunk(int id, Vector2<int> position, int pixelWidth, int pixelHeight) :
	id{ id },
	position{ position },
	pixelWidth{ pixelWidth },
	pixelHeight{ pixelHeight } {}

void Chunk::NotifyOnSetDataEvent(vector<vector<Pixel>>* newData)
{
	ChunkDataChangedEventArgs arg = ChunkDataChangedEventArgs(id, &pixelGrid, newData);
	OnSetDataEvent.Invoke(arg);
}

void Chunk::SubscribeObserverToOnSetDataEvent(shared_ptr<ChunkObserver> observer)
{
	OnSetDataEvent += std::bind(&ChunkObserver::OnDataSetEventHandler, observer.get(), std::placeholders::_1);
}

void Chunk::SetData(vector<vector<Pixel>> newData)
{
	NotifyOnSetDataEvent(&newData);
	pixelGrid = newData;
	
}

vector<vector<Pixel>>* Chunk::GetData(void)
{
	return &pixelGrid;
}

void Chunk::SetPosition(Vector2<int> newPosition)
{
	position = newPosition;
	for (size_t y = 0; y < pixelGrid.size(); ++y)
	{
		for (size_t x = 0; x < pixelGrid.size(); ++x)
		{
			int newX = position.x + x * pixelWidth;
			int newY = position.y + y * pixelHeight;
			pixelGrid[y][x].position.Set(newX, newY);
		}
	}
}

Vector2<int> Chunk::GetPosition(void)
{
	return position;
}

int Chunk::GetId(void)
{
	return id;
}
