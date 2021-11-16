#pragma once

#include "Core.h"
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
        void Draw();
        void Update();
    };
}