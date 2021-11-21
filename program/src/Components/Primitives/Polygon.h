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
    public:
        std::vector<eke::Line *> linearr;

    public:
        Polygon(const std::vector<sf::Vector2f> &points, const sf::Color &color, bool closed = false);
        Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed = false);
        ~Polygon();

    public:
        // Experimental
        void Fill(const sf::Color &color);
        void SetPosition(const sf::Vector2f &pos);
        void SetPosition(const float &posx, const float &posy);
        void ToString();
        void PollEvents();
        void Update();
        void Draw();

    private:
        void InitInitialImgVals();
        void CreateEntity(const sf::Color &color);

    private:
        unsigned int minx;
        unsigned int maxx;
        unsigned int miny;
        unsigned int maxy;
        sf::Color outlinecolor;
        sf::Color fillcolor;
        sf::Vector2f center;

    public:
        Polygon() = delete;
        Polygon(const Polygon &other) = delete;
        Polygon(Polygon &&other) = delete;
        Polygon &operator=(const Polygon &other) = delete;
        Polygon &operator=(Polygon &&other) = delete;
    };
}

#endif