#include <SFML/Graphics.hpp>
#include "Primitives/Pixel.h"
#include "Core.h"

using namespace std;

int main()
{
    eke::Globals::Init();

    sf::RectangleShape rs;
    rs.setSize(sf::Vector2f(75.f, 75.f));
    rs.setPosition(100, 100);
    rs.setOrigin(rs.getSize().x / 2, rs.getSize().y / 2);
    rs.setFillColor(sf::Color(73, 230, 107, 100));
    bool isgrabbed = true;
    rs.setOutlineThickness(1.f);
    rs.setOutlineColor(sf::Color::Red);

    eke::Line *line = new eke::Line(sf::Vector2f(50, 300), sf::Color::Green, sf::Vector2f(750, 300), sf::Color::Red);
    eke::Line *line2 = new eke::Line(sf::Vector2f(0, 0), sf::Color::Green, sf::Vector2f(800, 600), sf::Color::Red);

    eke::Button *btn1 = new eke::Button("Grab/Release");
    btn1->SetPosition(sf::Vector2f(btn1->GetPosition().x + btn1->GetSize().x / 2, btn1->GetPosition().y + btn1->GetSize().y / 2));
    btn1->SetOnClickEvent([](void *grabbed)
                          { if (*((bool *)grabbed) == true)
                        {
                            *((bool *)grabbed) = false;
                        }
                        else
                        {
                            *((bool *)grabbed) = true;
                        } },
                          (void *)&isgrabbed);

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
            btn1->PollEvents();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            line2->Move(sf::Vector2f(2, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            line2->Move(sf::Vector2f(-2, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            line2->Move(sf::Vector2f(0, -2));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            line2->Move(sf::Vector2f(0, 2));
        }

        if (isgrabbed)
        {
            rs.setPosition(eke::Globals::MousePosition);
        }

        // Update
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        fpstimer.Update(eke::Globals::DeltaTime);
        btn1->Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

        btn1->Draw();

        eke::Globals::RenderWindow->draw(rs);

        // eke::Clip::Clipp2(rs.getGlobalBounds(), *line);
        // eke::Clip::Clipp2(rs.getGlobalBounds(), *line2);

        eke::Clip::Clipp3(rs.getGlobalBounds(), *line);
        eke::Clip::Clipp3(rs.getGlobalBounds(), *line2);

        eke::Globals::RenderWindow->display();
    }
    eke::Globals::CleaUp();
    return 0;
}