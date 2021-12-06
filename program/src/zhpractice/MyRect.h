#ifndef MYRECT_HPP
#define MYRECT_HPP 1

#include "Core/Globals.h"
#include <SFML/Graphics.hpp>

namespace eke
{
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
        sf::RectangleShape *r;
        sf::CircleShape *c1;
        sf::CircleShape *c2;
        sf::CircleShape *c3;
        sf::CircleShape *c4;
        MyRect(const sf::Vector2f &size, const sf::Color &color);
        ~MyRect();
        void SetPosition(const sf::Vector2f &pos);
        sf::Vector2f GetSize();
        sf::Vector2f GetTopLeftP();
        sf::Vector2f GetTopRightP();
        sf::Vector2f GetBotLeftP();
        sf::Vector2f GetBotRightP();
        void Update();
        void Draw();
    };
}

#endif