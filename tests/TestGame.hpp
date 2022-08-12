#pragma once
#include <rain/Game.hpp>
using std::string;
class TestGame :
    public Game
{
    // Inherited via Game
    virtual void Initialize(void) override;
    virtual void Update(void) override;
    virtual void Render(void) override;
    virtual void Quit(void) override;

public:
    TestGame(string gameName, int framerate, int screenWidth, int screenHeight, string assetRootPath);
};

