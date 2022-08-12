#pragma once
#include <SDL.h>
#include <rain/rendering/Renderer.hpp>
#include <string>
#include <memory>
#include <rain/entities/EntityManager.hpp>
#include <rain/components/RenderableManager.hpp>

using std::string;
using std::unique_ptr;

class Game
{

private:
	string assetRootPath = "";
	string gameName = "Game";
	int framerate = 60;
	int screenWidth = 1280;
	int screenHeight = 720;
	bool editorEnabled = false;

	SDL_Window* window;
	unique_ptr<Renderer> renderer;

	bool EngineInitialize(void);
	void EngineUpdate(void);
	void EngineRender(void);
	void EngineQuit(void);
	void OnQuit(void);

protected:
	shared_ptr<AssetManager> assetManager;
	shared_ptr<EntityManager> entityManager;
	shared_ptr<RenderLayerManager> renderLayerManager;
	shared_ptr<RenderableManager> renderableManager;

	virtual void Initialize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;
	virtual void Quit(void) = 0;

public:
	bool hasQuit = false;

	Game(string gameName, int framerate, int screenWidth, int screenHeight, string assetRootPath);
	virtual ~Game(void);

	void ToggleEditorOverlay(bool state);
	void Start(void);
	void Play(void);
	void Close(void);

};

