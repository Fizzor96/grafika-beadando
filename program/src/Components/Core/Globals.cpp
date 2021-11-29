#include "Globals.h"

namespace eke
{
    // Init state
    sf::ContextSettings *Globals::CurrentContextSettings;
    sf::RenderWindow *Globals::RenderWindow;
    sf::Clock *Globals::Clock;
    sf::Event *Globals::Event;
    sf::Font Globals::GameFont;
    eke::Timer *Globals::fpstimer;

    // Update state
    sf::Vector2f Globals::MousePosition;
    float Globals::FPS = 60;
    float Globals::DeltaTime;

    void Globals::Init()
    {
        // Context setting
        eke::Globals::CurrentContextSettings = new sf::ContextSettings(0U, 0U, 0U, 1U, 1U, 0U, false);
        // Renderwindow
        eke::Globals::RenderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Grafika beadando - Szoke Dominik - FPS: 0", sf::Style::Default, *CurrentContextSettings);
        // Window position
        // eke::Globals::RenderWindow->setPosition(sf::Vector2i(0, 0));
        // Framerate
        eke::Globals::RenderWindow->setFramerateLimit(eke::Globals::FPS);
        // Set keyrepeat
        eke::Globals::RenderWindow->setKeyRepeatEnabled(false);
        // Gamefont
        eke::Globals::GameFont.loadFromFile("../assets/fonts/monogram.ttf");
        // Global timer
        eke::Globals::Clock = new sf::Clock();
        // Event
        eke::Globals::Event = new sf::Event();
        // Fps timer
        eke::Globals::fpstimer = new eke::Timer(0.2f, true);
        eke::Globals::fpstimer->SetExpiredCallback(eke::Globals::FpsTimerCallback);
    }

    void Globals::Update()
    {
        eke::Globals::fpstimer->Update(eke::Globals::DeltaTime);
        eke::Globals::UpdateMousePos();
    }

    void Globals::PollEvents()
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

    void Globals::CleaUp()
    {
        delete eke::Globals::CurrentContextSettings;
        delete eke::Globals::RenderWindow;
        delete eke::Globals::Event;
        delete eke::Globals::Clock;
        delete eke::Globals::fpstimer;
    }

    sf::Texture Globals::CreateDummyTexture(const unsigned int &width, const unsigned int &height, const sf::Color &color)
    {
        sf::Image img;
        img.create(width, height, color);
        sf::Texture texture;
        texture.loadFromImage(img, sf::IntRect(0, 0, width, height));
        return texture;
    }

    void Globals::FpsTimerCallback()
    {
        float fps = 1.f / eke::Globals::DeltaTime;
        eke::Globals::RenderWindow->setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps)));
    }

    void Globals::UpdateMousePos()
    {
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
    }
}