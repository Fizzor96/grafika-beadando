#ifndef MYRECT_HPP
#define MYRECT_HPP 1

#include "Core/Globals.h"
#include "zh1.h"
#include <SFML/Graphics.hpp>

namespace eke
{
    class zh1;
    class MyRect
    {
    private:
        bool grabTopLeft;
        bool grabTopRight;
        bool grabBotRight;
        bool grabBotLeft;
        void MoveByTopLeftP();
        void MoveByTopRightP();
        void MoveByBotRightP();
        void MoveByBotLeftP();
        void SizeByBotRightP();

    public:
        MyRect(const sf::Vector2f &size, const sf::Color &color);
        ~MyRect();

        zh1 *instance;
        sf::RectangleShape *r;
        sf::CircleShape *c1;
        sf::CircleShape *c2;
        sf::CircleShape *c3;
        sf::CircleShape *c4;

        void SetPosition(const sf::Vector2f &pos);
        sf::Vector2f GetSize();
        sf::Vector2f GetTopLeftP();
        sf::Vector2f GetTopRightP();
        sf::Vector2f GetBotLeftP();
        sf::Vector2f GetBotRightP();
        sf::Color GetColor() const;
        void Update();
        void Draw();
    };
}

#endif