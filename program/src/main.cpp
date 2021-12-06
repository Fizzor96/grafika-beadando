#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::zh1 *zh1 = new eke::zh1();
    // eke::Controller::Init();

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
            // eke::Controller::PollEvents();
        }

        eke::Globals::Update();
        // eke::Controller::Update();
        zh1->Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        // eke::Controller::Draw();
        zh1->Draw();

        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}