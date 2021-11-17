#ifndef CLIP_HPP
#define CLIP_HPP 1

#include <SFML/Graphics.hpp>

#include "Core/Globals.h"
#include "Primitives/Line.h"
#include <thread>

namespace eke
{
    class Line;

    class Clip
    {
    private:
        static const unsigned int TOP;
        static const unsigned int BOTTOM;
        static const unsigned int LEFT;
        static const unsigned int RIGHT;
        static unsigned int OutCode(const sf::IntRect &rect, const sf::Vector2f &p);

    public:
        static void Clipp(const sf::IntRect &rect, eke::Line *line);
        Clip() = delete;
        ~Clip() = delete;
    };
}

#endif