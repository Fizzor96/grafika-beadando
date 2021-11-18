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
        float thickness;

    public:
        std::vector<eke::Pixel *> vertexarr;

        sf::Vector2f p0;
        sf::Vector2f p1;
        sf::Color c1;
        sf::Color c2;

        Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color = sf::Color::White);
        Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor);
        ~Line();

        // Setting the starting point of the line
        void SetPosition(const sf::Vector2f &pos);

        void SetThickness(const float &factor);
        float GetThickness() const;

        // Experimental
        sf::Color *GetPixelColorByPos(const sf::Vector2f &pixelpos) const;

        void Draw();

        Line() = delete;
        Line(const eke::Line &other) = delete;
        Line(eke::Line &&other) = delete;
    };
}

#endif