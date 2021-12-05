#ifndef HERMITE2_HPP
#define HERMITE2_HPP 1

#include "Core/Globals.h"
#include "Curve2.h"
#include <SFML/Graphics.hpp>

namespace eke
{
    class Curve2;

    class Hermite
    {
    public:
        double weight;
        sf::Vector2f p0, p1, q0, q1;

        Hermite(const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &q0, const sf::Vector2f &q1, const double &weight = 1.0);

        static double H0(double t);
        static double H1(double t);
        static double H2(double t);
        static double H3(double t);
    };

    class Hermite2
    {
    private:
        Curve2 *curve;

    public:
        Hermite2(const sf::Color &color, const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &q0, const sf::Vector2f &q1, int n = 255);
        Hermite2(const sf::Color &color, const Hermite &arc, int n = 255);
        ~Hermite2();
        void Draw();
    };
}

#endif