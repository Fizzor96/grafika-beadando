#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 1

#include "Line.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace eke
{
    class Rectangle
    {
    public:
        std::vector<eke::Line *> lines;
        Rectangle(const sf::Vector2f &size, const sf::Vector2f &centerpos, const sf::Color &color);
        Rectangle(const float &width, const float &height, const float &centerx, const float &centery, const sf::Color &color);
        void Draw();
        ~Rectangle();
    };
}

#endif