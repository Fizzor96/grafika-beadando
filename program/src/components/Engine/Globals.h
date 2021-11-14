#pragma once
#include "SFML/Graphics.hpp"
#include "Engine/Timer.h"

namespace eke
{
    class Globals
    {
    public:
        static void Init()
        {
            // Context setting
            eke::Globals::CurrentContextSettings = new sf::ContextSettings(0U, 0U, 3U, 1U, 1U, 0U, false);
            // Renderwindow
            eke::Globals::RenderWindow = new sf::RenderWindow(sf::VideoMode(1280, 1024), "Grafika beadando - Szoke Dominik - FPS: 0", sf::Style::Default, *CurrentContextSettings);
            // Window position
            eke::Globals::RenderWindow->setPosition(sf::Vector2i(0, 0));
            // Framerate
            eke::Globals::RenderWindow->setFramerateLimit(eke::Globals::FPS);
            // Gamefont
            eke::Globals::GameFont.loadFromFile("../assets/fonts/monogram.ttf");
            // Global timer
            eke::Globals::Clock = new sf::Clock();
            // Event
            eke::Globals::Event = new sf::Event();
        }

        static void Start()
        {
            eke::Timer fpstimer(0.5f, true);

            fpstimer.SetExpiredCallback([]()
                                        {
                                            float fps = 1.f / eke::Globals::DeltaTime;
                                            eke::Globals::RenderWindow->setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps))); });
            fpstimer.Start();

            while (eke::Globals::RenderWindow->isOpen())
            {
                eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

                eke::Globals::PollEvents();
                eke::Globals::Update();
                fpstimer.Update(eke::Globals::DeltaTime);
                eke::Globals::Draw();
            }
        }

        static void CleaUp()
        {
            delete eke::Globals::CurrentContextSettings;
            delete eke::Globals::RenderWindow;
            delete eke::Globals::Event;
            delete eke::Globals::Clock;
        }

        // Helper to create dummy texture
        static sf::Texture CreateDummyTexture(const unsigned int &width, const unsigned int &height, const sf::Color &color)
        {
            sf::Image img;
            img.create(width, height, color);
            sf::Texture texture;
            texture.loadFromImage(img, sf::IntRect(0, 0, width, height));
            return texture;
        }

    private:
        static void PollEvents()
        {
            while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
            {
                if ((*eke::Globals::Event).type == sf::Event::Closed)
                    eke::Globals::RenderWindow->close();
                if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Escape)
                {
                    eke::Globals::RenderWindow->close();
                }

                // Pollevents Here
            }
        }

        static void Update()
        {
            eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
            // Update here
        }

        static void Draw()
        {
            eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));

            // Draw here

            eke::Globals::RenderWindow->display();
        }

    public:
        // Init state
        static sf::ContextSettings *CurrentContextSettings;
        static sf::RenderWindow *RenderWindow;
        static sf::Event *Event;
        static sf::Clock *Clock;
        static sf::Font GameFont;
        // Update state
        static float FPS;
        static float DeltaTime;
        static sf::Vector2f MousePosition;

    public:
        Globals() = delete;
        Globals(const Globals &other) = delete;
        Globals(Globals &&other) = delete;
        ~Globals() = delete;
    };

    // Init state
    sf::ContextSettings *Globals::CurrentContextSettings;
    sf::RenderWindow *Globals::RenderWindow;
    sf::Clock *Globals::Clock;
    sf::Event *Globals::Event;
    sf::Font Globals::GameFont;

    // Update state
    sf::Vector2f Globals::MousePosition;
    float Globals::FPS = 60;
    float Globals::DeltaTime;
}
