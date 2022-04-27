#include "Game.hpp"
#include <iostream>

Game::Game(string gameName, int framerate, int screenWidth, int screenHeight)
{
	this->gameName = gameName;
	this->framerate = framerate;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

Game::~Game(void)
{
	SDL_DestroyWindow(window);

	delete(renderer);
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

	renderer = new Renderer(window, screenWidth, screenHeight);
}

void Game::EngineUpdate(void)
{
}

void Game::EngineRender(void)
{
}

void Game::EngineQuit(void)
{
}


void Game::ToggleEditorOverlay(bool state)
{
}

void Game::Start(void)
{
}

void Game::Play(void)
{

	SDL_Delay(framerate);
}

void Game::Exit(void)
{
}
