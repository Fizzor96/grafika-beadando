#ifndef LINE_HPP
#define LINE_HPP 1

#include "Core/Globals.h"
#include "Pixel.h"
#include <vector>

namespace eke
{
    class Pixel;

    class Line
    {
    private:
        sf::Color c1;
        sf::Color c2;
        std::vector<eke::Pixel *> *vertexarr;

    public:
        sf::Vector2f *p0;
        sf::Vector2f *p1;

        // TODO: Issue with eke::Line ctors -> can't pass vector2f as ref or ptr nor value
        Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color = sf::Color::White);
        Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor);
        ~Line();

        void Draw();

        Line() = delete;
        Line(const eke::Line &other) = delete;
        Line(eke::Line &&other) = delete;
    };
}

#endif