#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::Controller::Init();
    // eke::Bezier2Arc *bez = new eke::Bezier2Arc(sf::Color::Yellow);

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
            eke::Controller::PollEvents();
            // bez->PollEvents();
        }

        eke::Globals::Update();
        eke::Controller::Update();
        // bez->Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        eke::Controller::Draw();
        // bez->Draw();

        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}