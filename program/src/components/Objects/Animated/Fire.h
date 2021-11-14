#pragma once

#include <SFML/Graphics.hpp>

#include "Engine/Globals.h"
#include "Engine/Entity.h"
#include "Engine/Animation.h"

namespace eke
{
    class Fire : public Entity
    {
    public:
        Fire(/* args */);
        ~Fire();
    };

    Fire::Fire(/* args */)
    {
    }

    Fire::~Fire()
    {
    }

}