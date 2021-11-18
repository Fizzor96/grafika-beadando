#ifndef CLIP_HPP
#define CLIP_HPP 1

#include <SFML/Graphics.hpp>

#include "Core/Globals.h"
#include "Primitives/Line.h"
#include "Primitives/Pixel.h"
#include <vector>

namespace eke
{
    class Line;
    class Pixel;

    class Clip
    {
    private:
        typedef unsigned int BYTE;
        static const BYTE TOP;
        static const BYTE BOTTOM;
        static const BYTE LEFT;
        static const BYTE RIGHT;
        static BYTE OutCode(const sf::FloatRect &rect, const sf::Vector2f &p);
        eke::Line *testline;
        std::vector<sf::Vector2f> matchingcoords;

    public:
        Clip();
        ~Clip();
        void Clipp(const sf::FloatRect &rect, sf::Vector2f pf0, sf::Vector2f pf1);
        void Clipp2(const sf::FloatRect &rect, const eke::Line &line);
        Clip(const Clip &other) = delete;
    };
}

#endif