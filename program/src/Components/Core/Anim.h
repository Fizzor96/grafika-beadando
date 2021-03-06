#ifndef ANIM_HPP
#define ANIM_HPP 1

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
        sf::IntRect GetAnimRect() const;
        // 1.f == 1 second
        void SetSwitchTime(const float &time);
        void SetAnimationRow(const unsigned int &row);
        void Update(const int &row, const float &deltatime);

        Anim() = delete;
        Anim(const Anim &other) = delete;
        Anim(Anim &&other) = delete;
        Anim &operator=(const Anim &other) = delete;
        Anim &operator=(Anim &&other) = delete;
    };
}

#endif