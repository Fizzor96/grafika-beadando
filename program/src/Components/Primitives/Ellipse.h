#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP 1

#include "Core/Globals.h"
#include "Pixel.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

namespace eke
{
    class Ellipse
    {
    private:
        std::vector<eke::Pixel *> vertexarr;

    public:
        Ellipse(int rx, int ry, int xc, int yc, sf::Color color);
        ~Ellipse();
        void Draw();

    public:
        Ellipse() = delete;
        Ellipse(const eke::Ellipse &other) = delete;
        Ellipse(Ellipse &&other) = delete;
    };
}

#endif