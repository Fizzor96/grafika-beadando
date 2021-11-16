#pragma once

#include "Core.h"
#include "Core/Globals.h"

namespace eke
{
    class Line
    {
    private:
        sf::VertexArray *line;

    public:
        Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color = sf::Color::White);
        Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor);
        ~Line();
        void Update();
        void Draw();

        Line() = delete;
        Line(const eke::Line &other) = delete;
        Line(eke::Line &&other) = delete;
    };
}