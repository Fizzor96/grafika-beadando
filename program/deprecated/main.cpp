#include <iostream>
#include "SFML/Graphics.hpp"
#include "MyText.h"
#include "Game.h"

int main()
{
    if (!Game::Init())
    {
        std::cerr << "Init failed!\n";
    }
    Game::Run();
    return 0;
}