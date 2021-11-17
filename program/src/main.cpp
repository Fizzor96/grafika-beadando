#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Controller.h"

using namespace std;

int main()
{
    eke::Globals::Init();

    sf::RectangleShape rs;
    rs.setSize(sf::Vector2f(150.f, 75.f));
    rs.setPosition(20, 20);
    // rs.setOrigin(rs.getSize().x / 2, rs.getSize().y / 2);
    rs.setFillColor(sf::Color(73, 230, 107, 100));
    // rs.setFillColor(sf::Color::Green);
    rs.setOutlineThickness(1.f);
    rs.setOutlineColor(sf::Color::Red);

    eke::Line line(sf::Vector2f(0, 0), sf::Vector2f(800, 600));

    eke::Timer fpstimer(0.5f, true);
    fpstimer.SetExpiredCallback(eke::Globals::FpsTimerCallback);

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            if ((*eke::Globals::Event).type == sf::Event::Closed)
            {
                eke::Globals::RenderWindow->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                eke::Globals::RenderWindow->close();
            }
        }

        // Update
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        fpstimer.Update(eke::Globals::DeltaTime);
        // rs.setPosition(eke::Globals::MousePosition);

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        eke::Globals::RenderWindow->draw(rs);
        // eke::Clip::Clipp(rs.getTextureRect(), &line);
        // line.Draw();
        eke::Globals::RenderWindow->display();
    }
    eke::Globals::CleaUp();
    return 0;
}