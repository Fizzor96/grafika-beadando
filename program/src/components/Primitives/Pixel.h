#ifndef PIXEL_HPP
#define PIXEL_HPP 1

#include "Core/Globals.h"
#include "Core/Entity.h"

namespace eke
{
    class Pixel : public Entity
    {
    private:
        sf::Vector2f pos;
        sf::Color color;

    public:
        Pixel();
        Pixel(const sf::Vector2f &position);
        Pixel(const sf::Vector2f &position, const sf::Color &color);
        ~Pixel();

        void SetPosition(const sf::Vector2f &pos);
        sf::Vector2f GetPosition() const;
        sf::Color GetColor() const;

        void SetScale(const sf::Vector2f &factor);

        void PollEvents() override;
        void Update() override;
        void Draw() override;
    };
}

#endif