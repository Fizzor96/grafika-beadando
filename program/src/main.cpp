#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::Controller::Init();

    eke::Crosshair cr(sf::Vector2f(75, 75), true);
    eke::Ellipse2 ell(200.f, 200.f, 100.f, 100.f);
    eke::Polygon poli(ell.positions, sf::Color::Yellow, true);
    // poli.SetPosition(300, 300);

    sf::CircleShape circle(1.f);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(sf::Vector2f(circle.getTextureRect().width / 2, circle.getTextureRect().height / 2));
    circle.setPosition(sf::Vector2f(200, 200));

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            eke::Globals::PollEvents();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                poli.SetPosition(300, 300);
                circle.setPosition(300, 300);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                poli.SetPosition(100, 100);
                circle.setPosition(100, 100);
            }
        }

        eke::Globals::Update();
        cr.Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        for (size_t i = 0; i < poli.linearr.size(); i++)
        {
            // eke::Clip::Clipp3(cr.GetGlobalBounds(), *poli.linearr[i]);
            eke::Clip::Clipp2(cr.GetGlobalBounds(), *poli.linearr[i]);
        }

        // poli.Draw();

        cr.Draw();
        eke::Globals::RenderWindow->draw(circle);

        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}