#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Globals.h"

#include "components/UI/Button.h"
#include "components/Primitives/Pixel.h"
#include "components/Primitives/Ellipse.h"

using namespace std;

int main()
{
    sf::RenderWindow w(sf::VideoMode(1280, 1024), "Grafika beadando - Szoke Dominik - FPS: 0", sf::Style::Default);
    w.setPosition(sf::Vector2i(0, 0));
    w.setFramerateLimit(eke::Globals::FPS);
    eke::Globals::Init(&w);

    eke::Button *btn1 = new eke::Button("Start", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 100.f));
    btn1->SetOnClickEvent([]()
                          { printf("Hello World!\n"); });

    eke::Button *btn2 = new eke::Button("Exit", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 200.f));
    btn2->SetOnClickEvent([]()
                          { eke::Globals::RenderWindow->close(); });

    sf::Clock clock;
    float lasttime = 0;
    float currtime;
    float timer = 1.f;
    float fps;

    while (w.isOpen())
    {
        currtime = clock.restart().asSeconds();
        fps = 1.f / currtime;
        lasttime = currtime;
        timer -= currtime;

        while (w.pollEvent(*eke::Globals::Event))
        {
            if ((*eke::Globals::Event).type == sf::Event::Closed)
                w.close();

            if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Escape)
            {
                w.close();
            }

            if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Space)
            {
                // Asd
            }

            btn1->PollEvents();
            btn2->PollEvents();
        }

        eke::Globals::Update();
        if (timer <= 0)
        {
            w.setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps)));
            timer = 1.f;
        }
        btn1->Update();
        btn2->Update();

        w.clear(sf::Color(54, 49, 60, 255));
        btn1->Draw();
        btn2->Draw();
        w.display();
    }
    return 0;
}