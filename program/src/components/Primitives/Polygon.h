#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Pixel.h"
#include <vector>
#include <iostream>

namespace eke
{
    class Polygon
    {
    public:
        std::vector<eke::Line *> linearr;

    public:
        Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed = false);
        ~Polygon();
        void Draw();
    };
}

#endif