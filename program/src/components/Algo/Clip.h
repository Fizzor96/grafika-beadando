#ifndef CLIP_HPP
#define CLIP_HPP 1

#include <SFML/Graphics.hpp>

#include "Core/Globals.h"
#include "Primitives/Line.h"
#include "Primitives/Pixel.h"

#include <vector>
#include <iostream>

namespace eke
{
    class Line;
    class Pixel;

    typedef unsigned int BYTE;

    class Clip
    {
    private:
        static const BYTE TOP;
        static const BYTE BOTTOM;
        static const BYTE LEFT;
        static const BYTE RIGHT;
        static BYTE OutCode(const sf::FloatRect &rect, const sf::Vector2f &p);

    public:
        // DON'T USE THIS!
        static void Clipp(const sf::FloatRect &rect, sf::Vector2f p0, sf::Vector2f p1);
        // Better Solution?
        static void Clipp2(const sf::FloatRect &rect, const eke::Line &line);
        // True Cohen-Shutter
        static void Clipp3(const sf::FloatRect &rect, const eke::Line &line);

        Clip() = delete;
        Clip(const Clip &other) = delete;
        Clip(Clip &&other) = delete;
        Clip &operator=(const Clip &other) = delete;
        Clip &operator=(Clip &&other) = delete;
    };
}

#endif