#pragma once
#include "SFML/Graphics.hpp"

namespace eke
{
    // Class for global vars and helper funcitons
    class Globals
    {
    public:
        static void Init(sf::RenderWindow *renderwindow)
        {
            GameFont.loadFromFile("../assets/fonts/monogram.ttf");
            RenderWindow = renderwindow;
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

        static void Update()
        {
            eke::Globals::MousePosition = eke::Globals::RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*eke::Globals::RenderWindow));
        }

    public:
        static sf::Font GameFont;
        static sf::RenderWindow *RenderWindow;
        static float FPS;
        static sf::Vector2f MousePosition;
        static sf::Event *Event;

    public:
        Globals() = delete;
        Globals(const Globals &other) = delete;
        Globals(Globals &&other) = delete;
        ~Globals() = delete;
    };

    sf::Vector2f Globals::MousePosition;
    sf::Event *Globals::Event = new sf::Event();
    sf::Font Globals::GameFont;
    sf::RenderWindow *Globals::RenderWindow;
    float Globals::FPS = 60;
}
