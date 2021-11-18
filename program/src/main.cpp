#include <SFML/Graphics.hpp>
#include "Core.h"

using namespace std;

void MyRand()
{
    std::cout << (rand() % 100) << std::endl;
}

int main()
{
    srand(time(NULL));

    eke::Globals::Init();

    sf::RectangleShape rs;
    rs.setSize(sf::Vector2f(75.f, 75.f));
    rs.setPosition(100, 100);
    rs.setOrigin(rs.getSize().x / 2, rs.getSize().y / 2);
    rs.setFillColor(sf::Color(73, 230, 107, 100));
    bool isgrabbed = true;
    rs.setOutlineThickness(1.f);
    rs.setOutlineColor(sf::Color::Red);

    eke::Line line(sf::Vector2f(300, 100), sf::Color::Green, sf::Vector2f(400, 100), sf::Color::Red);
    eke::Line line2(sf::Vector2f(100, 500), sf::Color::Red, sf::Vector2f(500, 100), sf::Color::Green);

    eke::Ellipse2 ell(200, 500, 500, 200);
    std::vector<sf::Color> colors;
    for (size_t i = 0; i < ell.positions.size(); i++)
    {
        colors.push_back(sf::Color::Yellow);
    }

    eke::Polygon poli(ell.positions, colors, true);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // line2.Move(sf::Vector2f(2, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // line2.Move(sf::Vector2f(-2, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // line2.Move(sf::Vector2f(0, -2));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // line2.Move(sf::Vector2f(0, 2));
        }

        // Update
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        fpstimer.Update(eke::Globals::DeltaTime);

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        // eke::Globals::RenderWindow->draw(rs);

        // ell.Draw();

        // line.Draw();
        // line2.Draw();

        poli.Draw();

        eke::Globals::RenderWindow->display();
    }
    eke::Globals::CleaUp();
    return 0;
}