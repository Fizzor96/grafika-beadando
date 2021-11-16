#pragma once

#include <SFML/Graphics.hpp>

namespace eke
{
    // Basic Entity decl
    class Entity
    {
    protected:
        sf::Sprite *sprite;
        sf::Texture *texture;

    public:
        Entity() {}
        virtual ~Entity() {}
        virtual void PollEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}