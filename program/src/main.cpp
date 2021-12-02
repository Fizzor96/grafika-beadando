#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::Controller::Init();

    eke::Ellipse ell(180, 50, 200, 200, sf::Color::Yellow);
    eke::Pixel pix(200, 200);
    eke::Line line(sf::Vector2f(200, 200), sf::Vector2f(200, 200), sf::Color::Green);
    eke::Crosshair *cr = new eke::Crosshair(sf::Vector2f(75, 75), true);
    eke::Rectangle rect(50, 50, 100, 100, sf::Color::Red);

    // eke::Polygon poli(ell.lines, sf::Color::Green, true);

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
            eke::Controller::PollEvents();
            cr->PollEvents();
        }

        eke::Globals::Update();
        eke::Controller::Update();
        cr->Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        eke::Controller::Draw();
        for (size_t i = 0; i < ell.lines.size(); i++)
        {
            eke::Clip::CohenShutter(cr->GetGlobalBounds(), *ell.lines[i]);
        }
        for (size_t i = 0; i < rect.lines.size(); i++)
        {
            eke::Clip::CohenShutter(cr->GetGlobalBounds(), *rect.lines[i]);
        }

        // cr->Draw();
        // poli.Draw();
        // ell.Draw();
        // pix.Draw();
        // line.Draw();
        // rect.Draw();
        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}