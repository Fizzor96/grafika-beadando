#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Entity.h"
#include "Line.h"
#include "Pixel.h"
#include <vector>
#include <iostream>
#include <thread>

namespace eke
{
    class Polygon : public Entity
    {

    private:
        void InitInitialImgVals();

    private:
        unsigned int minx;
        unsigned int maxx;
        unsigned int miny;
        unsigned int maxy;
        sf::Color outlinecolor;
        sf::Color fillcolor;
        sf::Vector2f center;
        std::vector<eke::Line *> linearr;
        void CreateEntity(const sf::Color &color);

    public:
        Polygon(const std::vector<sf::Vector2f> &points, const sf::Color &color, bool closed = false);
        Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed = false);
        ~Polygon();

    public:
        void Fill(const sf::Color &color);
        void ToString();
        void PollEvents();
        void Update();
        void Draw();
    };
}

#endif