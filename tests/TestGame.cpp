#include "TestGame.hpp"
#include <rain/pixel/objects/Chunk.hpp>
shared_ptr<Renderable> rend;
Chunk chunk(0, { 300, 300 });

void TestGame::Initialize(void)
{
	printf("test game initialized\n");
	int textureId = assetManager->Create("square.png", "sq1", AssetType::TEXTURE);
	printf("loaded asset id %d\n", textureId);
	int entityId = entityManager->Create(Vector2<int>(500, 400), Vector2<int>(0, 0), Vector2<int>(10, 10));
	auto entity = entityManager->Get(entityId);

	shared_ptr<Renderable> renderable = renderableManager->Create(textureId, 0);
	renderable->position = entity->position;
	renderable->rotation = entity->rotation;
	renderable->scale = entity->scale;

	Component comp = Component(renderable->id, ComponentType::Renderable);
	entity->AddComponent(comp);

	rend = renderable;

	renderLayerManager->Create(0, "layer1", true);
	renderLayerManager->AddObjToLayer(0, renderable);

	int pixelDim = 5;
	auto chunkPos = chunk.GetPosition();
	vector<vector<Pixel>> data;
	for (int i = 0; i < 100; ++i) 
	{
		vector<Pixel> row;
		for (int j = 0; j < 100; ++j)
		{
			shared_ptr<Renderable> renderable = renderableManager->Create(textureId, 0);
			renderable->scale = { pixelDim, pixelDim};

			PixelType t = PixelType::ROCK;
			SDL_Color c = { 255, 255, 255, 255 };
			if (static_cast <float> (rand()) / static_cast <float> (RAND_MAX) < 0.5f)
			{
				c = { 255, 255, 255, 0 };
				t = PixelType::BLANK;
			}
			Pixel p(Vector2<int>(
				chunkPos.x + i * pixelDim, chunkPos.y + j * pixelDim), 
				c, 
				t, 
				PixelClassification::GRAINS);
			p.AttachRenderable(renderable);
			row.push_back(p);

			renderLayerManager->AddObjToLayer(0, renderable);
		}
		data.push_back(row);
	}
	chunk.SetData(data, pixelDim, pixelDim);
	
	printf("created entity: %d\n", entityId);
}

void TestGame::Update(void)
{
	//printf("test game updating");

	//SDL_GetMouseState(&rend->position.x, &rend->position.y);
	Vector2<int> mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	//chunk.SetPosition(mousePos);
	chunk.Simulate();
}

void TestGame::Render(void)
{
}

void TestGame::Quit(void)
{
	printf("test game quit\n	");
}

TestGame::TestGame(string gameName, int framerate, int screenWidth, int screenHeight, string assetRootPath)
	: Game(gameName, framerate, screenWidth, screenHeight, assetRootPath)
{
}
