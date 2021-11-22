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
        sf::Vector2f p0;
        sf::Vector2f p1;
        sf::Color c1;
        sf::Color c2;

    public:
        std::vector<eke::Pixel *> vertexarr;
        std::vector<sf::Vector2f> positions;

    public:
        Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color = sf::Color::Black);
        Line(const float &beginx, const float &beginy, const float &endx, const float &endy, const sf::Color &color = sf::Color::Black);
        Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor);
        Line(const float &beginx, const float &beginy, const sf::Color &begincolor, const float &endx, const float &endy, const sf::Color &endcolor);
        ~Line();

        // Setting the starting point of the line and moving other verticies
        void SetPosition(const float &posx, const float &posy);
        // Setting the starting point of the line and moving other verticies
        void SetPosition(const sf::Vector2f &pos);
        // Move all verticies by given vector
        void Move(const float &posx, const float &posy);
        // Move all verticies by given vector
        void Move(const sf::Vector2f &vec);
        // Set line thickness
        void SetThickness(const float &factor);
        // Set line color
        void SetColor(const sf::Color &colorbegin, const sf::Color &colorend);
        // Get thickness
        float GetThickness() const;
        // Get beginning position of the line
        sf::Vector2f GetBeginPos() const;
        // Get end position of the line
        sf::Vector2f GetEndPos() const;
        // Get beginning color of the line
        sf::Color GetBeginColor() const;
        // Get end color of the line
        sf::Color GetEndColor() const;
        // Get color by vertex position (note: color pointer to be able to validate)
        sf::Color GetColorByVertexPos(const sf::Vector2f &pos) const;

        void Draw();

        Line() = delete;
        Line(const eke::Line &other) = delete;
        Line(eke::Line &&other) = delete;
        Line &operator=(const Line &other) = delete;
        Line &operator=(Line &&other) = delete;
    };
}

#endif