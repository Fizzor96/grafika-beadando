#include "Globals.h"

namespace eke
{
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

    // Scenes
    // static std::vector<eke::Scene *> Scenes;

    void fpscallback()
    {
        float fps = 1.f / eke::Globals::DeltaTime;
        eke::Globals::RenderWindow->setTitle(std::string("Grafika beadando - Szoke Dominik - fps: " + std::to_string((int)fps)));
    }

    void Globals::Init()
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

    void Globals::Start()
    {
        eke::Button *btn1 = new Button("Start", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 100.f));
        btn1->SetOnClickEvent([]()
                              { printf("Hello World!\n"); });

        eke::Fire *foje = new Fire();

        eke::Timer fpstimer(0.5f, true);
        fpstimer.SetExpiredCallback(fpscallback);
        fpstimer.Start();

        while (eke::Globals::RenderWindow->isOpen())
        {
            eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

            while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
            {
                eke::Globals::PollEvents();
                btn1->PollEvents();
            }

            eke::Globals::Update();
            fpstimer.Update(eke::Globals::DeltaTime);
            btn1->Update();
            foje->Update();

            eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
            eke::Globals::Draw();
            btn1->Draw();
            foje->Draw();
            eke::Globals::RenderWindow->display();
        }
    }

    void Globals::CleaUp()
    {
        delete eke::Globals::CurrentContextSettings;
        delete eke::Globals::RenderWindow;
        delete eke::Globals::Event;
        delete eke::Globals::Clock;
    }

    sf::Texture Globals::CreateDummyTexture(const unsigned int &width, const unsigned int &height, const sf::Color &color)
    {
        sf::Image img;
        img.create(width, height, color);
        sf::Texture texture;
        texture.loadFromImage(img, sf::IntRect(0, 0, width, height));
        return texture;
    }

    void Globals::PollEvents()
    {
        if ((*eke::Globals::Event).type == sf::Event::Closed)
            eke::Globals::RenderWindow->close();
        if ((*eke::Globals::Event).type == sf::Event::KeyPressed && (*eke::Globals::Event).key.code == sf::Keyboard::Escape)
        {
            eke::Globals::RenderWindow->close();
        }
    }

    void Globals::Update()
    {
        eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        // Update here
    }

    void Globals::Draw()
    {
        // Draw here
    }
}