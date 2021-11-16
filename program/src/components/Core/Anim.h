#pragma once

#include <SFML/Graphics.hpp>

namespace eke
{
    class Anim
    {
    public:
        sf::IntRect textureRect;

    private:
        sf::Vector2u imgCount;
        sf::Vector2u currImg;
        float totalTime;
        float switchTime;

    public:
        Anim(sf::Texture *texture, const sf::Vector2u imgCount, float switchTime);
        ~Anim();
        void Update(const int &row, const float &deltatime);
        Anim() = delete;
        Anim(const Anim &other) = delete;
        Anim(Anim &&other) = delete;
    };
}