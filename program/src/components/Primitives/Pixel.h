#ifndef PIXEL_HPP
#define PIXEL_HPP 1

#include "Core/Globals.h"
#include "Core/Entity.h"

namespace eke
{
    class Pixel : public Entity
    {
    public:
        // sf::Vector2f pos;
        sf::Color color;

    public:
        Pixel(const sf::Vector2f &position);
        Pixel(const sf::Vector2f &position, const sf::Color &color);
        ~Pixel();

        void SetScale(const sf::Vector2f &factor);

        void SetPosition(const sf::Vector2f &pos);
        void SetPosition(const float &posx, const float &posy);
        sf::Vector2f GetPosition() const;

        void PollEvents() override;
        void Update() override;
        void Draw() override;
    };
}

#endif