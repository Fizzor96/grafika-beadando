#pragma once

#include "Engine.h"
#include "Engine/Entity.h"

namespace eke
{
    class Panel : public Entity
    {
    private:
        sf::Text title;
        sf::FloatRect titlebb;
        sf::Text description;
        sf::FloatRect descriptionbb;

    public:
        Panel(const char *title, const char *desc);
        ~Panel();
    };
}