#ifndef BEZIER2ARC_HPP
#define BEZIER2ARC_HPP 1

#include "Algo/Binomial.h"
#include "Curve2.h"
#include "Primitives/Line.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

namespace eke
{
    class Curve2;

    struct Bezier
    {
        double p;
        sf::Vector2f p0, p1, p2, p3;

        Bezier(const double &p);
        Bezier(const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3, const double &p);

        static double B0(const double &t, const double &p);
        static double B1(const double &t, const double &p);
        static double B2(const double &t, const double &p);
        static double B3(const double &t, const double &p);
        static double BezierBernstein(const double &t, const int &n, const int &i);
    };

    class Bezier2Arc
    {
    private:
        unsigned int vectorsize;
        Curve2 *curve;
        sf::Color *color;
        std::vector<eke::Line *> lines;
        std::vector<sf::Vector2f> positions;

    public:
        // Use this ctor with noparam Update() and Draw()
        Bezier2Arc(const sf::Color &color);
        Bezier2Arc(const sf::Color &color, const Bezier &arc);
        Bezier2Arc(const sf::Color &color, const std::vector<sf::Vector2f> &vectors);
        ~Bezier2Arc();
        void PollEvents();
        void Update();
        void Update(const std::vector<sf::Vector2f> &vectors);
        void Draw();
    };
}

#endif