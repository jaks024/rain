#pragma once
#include <SDL.h>
#include "rendering/Renderer.hpp"
#include <string>

using std::string;

class Game
{

private:
	string gameName = "Game";
	int framerate = 60;
	int screenWidth = 1280;
	int screenHeight = 720;

	SDL_Window* window;
	Renderer* renderer;

	bool EngineInitialize(void);
	void EngineUpdate(void);
	void EngineRender(void);
	void EngineQuit(void);

protected:
	virtual void Initialize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;
	virtual void Quit(void) = 0;

public:
	Game(string gameName, int framerate, int screenWidth, int screenHeight);
	~Game(void);

	void ToggleEditorOverlay(bool state);
	void Start(void);
	void Play(void);
	void Exit(void);

};

