#include "TestGame.hpp"

void TestGame::Initialize(void)
{
	printf("test game initialized\n");
}

void TestGame::Update(void)
{
	//printf("test game updating");
}

void TestGame::Render(void)
{
}

void TestGame::Quit(void)
{
	printf("test game quit\n	");
}

TestGame::TestGame(string gameName, int framerate, int screenWidth, int screenHeight) 
	: Game(gameName, framerate, screenWidth, screenHeight)
{
}
