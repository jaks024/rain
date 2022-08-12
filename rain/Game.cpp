#include <iostream>
#include <rain/Game.hpp>

Game::Game(string gameName, int framerate, int screenWidth, int screenHeight, string assetRootPath)
{
	this->gameName = gameName;
	this->framerate = framerate;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->assetRootPath = assetRootPath;
}

Game::~Game(void)
{
	SDL_DestroyWindow(window);
}

bool Game::EngineInitialize(void)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create window
	this->window = SDL_CreateWindow(gameName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = std::make_unique<Renderer>(window, screenWidth, screenHeight);
	assetManager = std::make_shared<AssetManager>(renderer->GetRenderer(), assetRootPath);
	entityManager = std::make_shared<EntityManager>();
	renderLayerManager = std::make_shared<RenderLayerManager>();
	renderableManager = std::make_shared<RenderableManager>();
}

void Game::EngineUpdate(void)
{
	// TEMPORARY (TO BE MOVED TO INPUT MANAGER)
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			OnQuit();
			break;
		default:
			break;
		}
	}

}

void Game::EngineRender(void)
{
	renderer->Render(renderLayerManager, assetManager);
}

void Game::EngineQuit(void)
{
}

void Game::OnQuit(void)
{
	EngineQuit();
	Quit();
	hasQuit = true;
}


void Game::ToggleEditorOverlay(bool state)
{
	editorEnabled = state;
	// turn on editor 
}

void Game::Start(void)
{
	EngineInitialize();
	Initialize();
}

void Game::Play(void)
{
	EngineUpdate();
	Update();
	EngineRender();
	Render();

	SDL_Delay(framerate);
}

void Game::Close(void)
{
	SDL_Quit();
}
