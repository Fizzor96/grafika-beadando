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
        // Cohen-Shutter
        static void CohenShutter(const sf::FloatRect &rect, const eke::Line &line);
        // Better Solution?
        static void Clipp(const sf::FloatRect &rect, const eke::Line &line);

        Clip() = delete;
        Clip(const Clip &other) = delete;
        Clip(Clip &&other) = delete;
        Clip &operator=(const Clip &other) = delete;
        Clip &operator=(Clip &&other) = delete;
    };
}

#endif