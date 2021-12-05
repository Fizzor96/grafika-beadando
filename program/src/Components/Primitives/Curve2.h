#ifndef CURVE2_HPP
#define CURVE2_HPP 1

#include "Primitives/Line.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

namespace eke
{
    class Curve2
    {
    private:
        std::vector<eke::Line *> linearr;

    public:
        // Draw parametric curve 2D
        Curve2(const sf::Color &color, std::function<double(double)> func1, std::function<double(double)> func2, double a, double b, int n = 255);
        // Be aware: If n > 255 transition between colors is not working correctly!!!
        Curve2(const sf::Color &begincolor, const sf::Color &endcolor, std::function<double(double)> func1, std::function<double(double)> func2, double a, double b, int n = 255);
        ~Curve2();
        void Draw();

        Curve2() = delete;
        Curve2(const Curve2 &other) = delete;
        Curve2(Curve2 &&other) = delete;
        Curve2 &operator=(const Curve2 &other) = delete;
        Curve2 &operator=(Curve2 &&other) = delete;
    };
}

#endif