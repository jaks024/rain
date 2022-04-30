#include "TestGame.hpp"

void TestGame::Initialize(void)
{
	printf("test game initialized");
}

void TestGame::Update(void)
{
}

void TestGame::Render(void)
{
}

void TestGame::Quit(void)
{
}

TestGame::TestGame(string gameName, int framerate, int screenWidth, int screenHeight) 
	: Game(gameName, framerate, screenWidth, screenHeight)
{
}
