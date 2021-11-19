#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;

int main()
{
    eke::Globals::Init();

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
        }

        eke::Globals::Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        // Draw

        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}