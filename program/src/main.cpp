#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"

using namespace std;

int main()
{
    eke::Globals::Init();
    eke::Globals::Start();
    eke::Globals::CleaUp();

    // eke::Button *btn1 = new eke::Button("Start", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 100.f));
    // btn1->SetOnClickEvent([]()
    //                       { printf("Hello World!\n"); });

    // eke::Button *btn2 = new eke::Button("Exit", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 200.f));
    // btn2->SetOnClickEvent([]()
    //                       { eke::Globals::RenderWindow->close(); });

    // eke::Line *ln1 = new eke::Line(sf::Vector2f(25.f, 100.f), sf::Vector2f(800.f, 800.f), sf::Color::Red);
    // eke::Line *ln2 = new eke::Line(sf::Vector2f(50.f, 100.f), sf::Color::Blue, sf::Vector2f(680.f, 400.f), sf::Color::Yellow);

    // sf::Clock clock;
    // float lasttime = 0;
    // float delta;
    // float timer = 1.f;
    // float fps;

    // while (w.isOpen())
    // {
    //     delta = clock.restart().asSeconds();
    //     fps = 1.f / delta;
    //     lasttime = delta;
    //     timer -= delta;

    //     while (w.pollEvent(*eke::Globals::Event))
    //     {
    //         if ((*eke::Globals::Event).type == sf::Event::Closed)
    //             w.close();

    //         if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Escape)
    //         {
    //             w.close();
    //         }

    //         if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Space)
    //         {
    //             // Asd
    //         }

    //         btn1->PollEvents();
    //         btn2->PollEvents();
    //     }

    //     eke::Globals::Update();
    //     if (timer <= 0)
    //     {
    //         w.setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps)));
    //         timer = 1.f;
    //     }
    //     btn1->Update();
    //     btn2->Update();

    //     w.clear(sf::Color(54, 49, 60, 255));
    //     btn1->Draw();
    //     btn2->Draw();
    //     ln1->Draw();
    //     ln2->Draw();
    //     w.display();
    // }
    return 0;
}