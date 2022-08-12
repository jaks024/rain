#include "TestGame.hpp"

shared_ptr<Renderable> rend;

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
	
	printf("created entity: %d\n", entityId);
}

void TestGame::Update(void)
{
	//printf("test game updating");

	SDL_GetMouseState(&rend->position.x, &rend->position.y);
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
