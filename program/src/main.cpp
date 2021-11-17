#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Controller.h"

using namespace std;

int main()
{
    eke::Globals::Init();

    sf::RectangleShape rs;
    // rs.setSize(sf::Vector2f(150.f, 75.f));
    // rs.setPosition(20, 20);
    rs.setSize(sf::Vector2f(75.f, 75.f));
    rs.setPosition(100, 100);
    rs.setOrigin(rs.getSize().x / 2, rs.getSize().y / 2);
    rs.setFillColor(sf::Color(73, 230, 107, 100));
    bool isgrabbed = true;
    rs.setOutlineThickness(1.f);
    rs.setOutlineColor(sf::Color::Red);

    eke::Clip *clipper = new eke::Clip();

    eke::Line *line = new eke::Line(sf::Vector2f(44, 55), sf::Vector2f(444, 555));
    // std::cout << "clip: x1=" << line->p0->x << ", y1=" << line->p0->y << " x2=" << line->p1->x << ", y2=" << line->p1->y << "\n";

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                isgrabbed = !isgrabbed;
                if (isgrabbed)
                {
                    std::cout << "grabbed" << std::endl;
                }
                else
                {
                    std::cout << "not grabbed" << std::endl;
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            rs.setPosition(rs.getPosition().x + 1, rs.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            rs.setPosition(rs.getPosition().x - 1, rs.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            rs.setPosition(rs.getPosition().x, rs.getPosition().y - 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            rs.setPosition(rs.getPosition().x, rs.getPosition().y + 1);
        }

        if (isgrabbed)
        {
            rs.setPosition(eke::Globals::MousePosition);
        }

        // Update
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        fpstimer.Update(eke::Globals::DeltaTime);

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        eke::Globals::RenderWindow->draw(rs);
        clipper->Clipp2(rs.getGlobalBounds(), *line);

        eke::Globals::RenderWindow->display();
    }
    eke::Globals::CleaUp();
    return 0;
}