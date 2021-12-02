#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP 1

#include "Core/Globals.h"
#include "Line.h"
#include "Pixel.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

namespace eke
{
    class Ellipse
    {
    private:
        sf::Vector2f center;
        std::vector<eke::Pixel *> vertexarr;
        // std::vector<eke::Line *> filled;

    public:
        std::vector<eke::Line *> lines;
        Ellipse(int rx, int ry, int xc, int yc, sf::Color color);
        ~Ellipse();
        void SetPosition(const float &x, const float &y);
        void SetPosition(const sf::Vector2f pos);
        // void Fill();
        void Draw();

    public:
        Ellipse() = delete;
        Ellipse(const eke::Ellipse &other) = delete;
        Ellipse(Ellipse &&other) = delete;
    };
}

#endif