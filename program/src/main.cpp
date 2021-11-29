#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::Controller::Init();

    eke::Ellipse ell(180, 50, 200, 200, sf::Color::Yellow);
    eke::Pixel pix(200, 200);

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
            eke::Controller::PollEvents();
        }

        eke::Globals::Update();
        eke::Controller::Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        eke::Controller::Draw();
        ell.Draw();
        pix.Draw();
        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}