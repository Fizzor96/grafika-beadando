#ifndef CROSSHAIR_HPP
#define CROSSHAIR_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Globals.h"

namespace eke
{
    class Crosshair
    {
    public:
        sf::RectangleShape rs;
        bool isgrabbed;

        Crosshair(const sf::Vector2f &size, const bool &isgrabbed = false);
        ~Crosshair();

        void PollEvents();
        void Update();
        void Draw();

        Crosshair() = delete;
        Crosshair(const Crosshair &other) = delete;
        Crosshair(Crosshair &&other) = delete;
        Crosshair &operator=(const Crosshair &other) = delete;
        Crosshair &operator=(Crosshair &&other) = delete;
    };
}

#endif