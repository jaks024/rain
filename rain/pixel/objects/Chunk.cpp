#include <rain/pixel/objects/Chunk.hpp>

Chunk::Chunk(int id, Vector2<int> position) :
	id{ id },
	position{ position } {}

void Chunk::NotifyOnSetDataEvent(vector<vector<Pixel>>* newData)
{
	ChunkDataChangedEventArgs arg = ChunkDataChangedEventArgs(id, &pixelGrid, newData);
	OnSetDataEvent.Invoke(arg);
}

void Chunk::SubscribeObserverToOnSetDataEvent(shared_ptr<ChunkObserver> observer)
{
	OnSetDataEvent += std::bind(&ChunkObserver::OnDataSetEventHandler, observer.get(), std::placeholders::_1);
}

void Chunk::SetData(vector<vector<Pixel>> newData, int pixelWidth, int pixelHeight)
{
	NotifyOnSetDataEvent(&newData);
	pixelGrid = newData;
	this->pixelWidth = pixelWidth;
	this->pixelHeight = pixelHeight;
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
			pixelGrid[y][x].UpdateRenderable();
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

bool Chunk::RandomBool(void)
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX) < 0.5f;
}

void Chunk::SwapPixel(size_t fy, size_t fx, size_t ty, size_t tx)
{
	Pixel& f = pixelGrid[fy][fx];
	Pixel& t = pixelGrid[ty][tx];
	Pixel ftemp = f;
	f.SetData(t);
	t.SetData(ftemp);
}

bool Chunk::IsInRange(size_t y, size_t x)
{
	return 0 <= y && y < pixelGrid.size() && 0 <= x && x < pixelGrid[0].size();
}

bool Chunk::SimulateGrains(size_t y, size_t x)
{
	int newY = y + down.y;
	int newX = x + down.x;
	if (IsInRange(newY, newX) && pixelGrid[newY][newX].type == PixelType::BLANK)
	{
		SwapPixel(newY, newX, y, x);
		return true;
	}
	bool isDownLeft = RandomBool();
	newY = y + downLeft.y;
	newX = x + downLeft.x;
	if (isDownLeft && IsInRange(newY, newX) && pixelGrid[newY][newX].type == PixelType::BLANK)
	{
		SwapPixel(newY, newX, y, x);
		return true;
	}
	newY = y + downRight.y;
	newX = x + downRight.x;
	if (!isDownLeft && IsInRange(newY, newX) && pixelGrid[newY][newX].type == PixelType::BLANK)
	{
		SwapPixel(newY, newX, y, x);
		return true;
	}
	return false;
}

bool Chunk::SimulateLiquid(size_t y, size_t x)
{
	if (SimulateGrains(y, x))
	{
		return true;
	}
	bool isLeft = RandomBool();
	if (isLeft && pixelGrid[y + left.y][x + left.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + left.y][x + left.x], pixelGrid[y][x]);
		return true;
	}
	else if (!isLeft && pixelGrid[y + right.y][x + right.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + right.y][x + right.x], pixelGrid[y][x]);
		return true;
	}
	return false;
}

bool Chunk::SimulateGas(size_t y, size_t x)
{
	if (pixelGrid[y + up.y][x + up.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + up.y][x + up.x], pixelGrid[y][x]);
		return true;
	}

	bool isUpLeft = RandomBool();
	if (isUpLeft && pixelGrid[y + upLeft.y][x + upLeft.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + upLeft.y][x + upLeft.x], pixelGrid[y][x]);
		return true;
	}
	else if (!isUpLeft && pixelGrid[y + upRight.y][x + upRight.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + upRight.y][x + upRight.x], pixelGrid[y][x]);
		return true;
	}

	bool isLeft = RandomBool();
	if (isLeft && pixelGrid[y + left.y][x + left.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + left.y][x + left.x], pixelGrid[y][x]);
		return true;
	}
	else if (!isLeft && pixelGrid[y + right.y][x + right.x].type == PixelType::BLANK)
	{
		std::swap(pixelGrid[y + right.y][x + right.x], pixelGrid[y][x]);
		return true;
	}
	return false;
}

void Chunk::Simulate(void)
{
	SetPosition(position);
	for (int y = static_cast<int>(pixelGrid.size() - 1); y >= 0; --y)
	{
		for (int x = static_cast<int>(pixelGrid[0].size() - 1); x >= 0; --x)
		{
			switch (pixelGrid[y][x].classification)
			{
			case PixelClassification::GRAINS:
			{
				SimulateGrains(y, x);
				break;
			}
			//case PixelClassification::LIQUID:
			//{
			//	SimulateLiquid(y, x);
			//	break;
			//}
			//case PixelClassification::GAS:
			//{
			//	SimulateGas(y, x);
			//	break;
			//}
			default:
				break;
			}
		}
	}
}
