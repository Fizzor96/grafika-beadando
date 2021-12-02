#ifndef CROSSHAIR_HPP
#define CROSSHAIR_HPP 1

#include "Core/Entity.h"
#include "Core/Globals.h"
#include "Core/Timer.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace eke
{
    class Crosshair : public Entity
    {
    public:
        sf::RectangleShape rs;
        bool isgrabbed;
        std::vector<sf::Vector2f> track;
        int posindicator;

        Crosshair(const sf::Vector2f &size, const bool &isgrabbed = false);
        ~Crosshair();

        sf::FloatRect GetGlobalBounds() const;
        void SetTrack(const std::vector<sf::Vector2f> &track);

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