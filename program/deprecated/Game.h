#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "SFML/Graphics.hpp"

#include "MyText.h"
#include "Entity.h"

class MyText;

class Game
{
public:
    static bool Init();
    static void SetDebug(const bool &isEnabled);
    static void Run();
    static void Close();
    static void PollEvents();
    static void Update();
    static void Draw();
    static sf::RenderWindow *GetCurrentInstance();
    static void AddEntity(Entity *ent);
    static void RemoveEntity();

public:
    static sf::RenderWindow *Window;
    static sf::Event Event;
    static unsigned int WinWidth;
    static unsigned int WinHeight;
    static std::vector<Entity *> Entities;
    static float FrameTime;

public:
    Game() = delete;
    ~Game() = delete;
    Game(const Game &other) = delete;
    Game(Game &&other) = delete;

private:
    static bool isDebugEnabled;
};
