#pragma once

#include <SFML/Graphics.hpp>

#include "Engine/Entity.h"

namespace eke
{
    class Textfield : public Entity
    {
    private:
        /* data */
    public:
        Textfield();
        ~Textfield();
    };

    Textfield::Textfield()
    {
    }

    Textfield::~Textfield()
    {
    }

}