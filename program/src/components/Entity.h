#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

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
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}