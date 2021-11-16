#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Controller.h"

using namespace std;

int main()
{
    eke::Globals::Init();

    eke::Button *btn1 = new eke::Button("Start", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 100.f));
    btn1->SetOnClickEvent([]()
                          {
                              static unsigned int tmpc = 0;
                              tmpc++;
                              printf("Hello World! %i\n", tmpc);
                          });

    eke::Button *btn2 = new eke::Button("Exit", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, btn1->GetPosition().y + btn1->GetSize().y / 2 + 50.f));
    btn2->SetOnClickEvent([]()
                          { eke::Globals::RenderWindow->close(); });

    eke::Fire *foje = new eke::Fire();

    eke::Line line(sf::Vector2f(0, 0), sf::Color::Red, sf::Vector2f(800.f, 600.f), sf::Color::Green);

    eke::Ellipse *ell = new eke::Ellipse(sf::Vector2f(50.f, 100.f));
    ell->setPosition(350.f, 350.f);
    // ell->setFillColor(sf::Color(0, 0, 0, 0));
    ell->setFillColor(sf::Color::Green);
    ell->setOutlineColor(sf::Color::Black);
    ell->setOutlineThickness(5.f);

    eke::Pixel *pix = new eke::Pixel(ell->getCenter(), sf::Color::Red);
    pix->SetScale(sf::Vector2f(3.f, 3.f));

    eke::Timer fpstimer(0.5f, true);
    fpstimer.SetExpiredCallback([]()
                                {
                                    float fps = 1.f / eke::Globals::DeltaTime;
                                    eke::Globals::RenderWindow->setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps)));
                                });

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            if ((*eke::Globals::Event).type == sf::Event::Closed)
            {
                eke::Globals::RenderWindow->close();
            }

            // PollEvents
            btn1->PollEvents();
            btn2->PollEvents();
        }

        // Update
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        fpstimer.Update(eke::Globals::DeltaTime);
        btn1->Update();
        btn2->Update();
        foje->Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        // Draw
        btn1->Draw();
        btn2->Draw();
        line.Draw();
        ell->Draw();
        pix->Draw();
        foje->Draw();
        eke::Globals::RenderWindow->display();
    }
    eke::Globals::CleaUp();
    return 0;
}