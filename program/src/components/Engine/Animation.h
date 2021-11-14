#pragma once

#include "Engine.h"

namespace eke
{
    class Animation
    {
    public:
        sf::IntRect textureRect;

    private:
        sf::Vector2u imgCount;
        sf::Vector2u currImg;
        float totalTime;
        float switchTime;

    public:
        Animation(sf::Texture *texture, const sf::Vector2u imgCount, float switchTime);
        ~Animation();
        void Update(const int &row, const float &deltatime);
    };
}