#ifndef POLYGON_HPP
#define POLYGON_HPP 1

#include "Core/Entity.h"
#include "Line.h"
#include "Pixel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <vector>

namespace eke
{
    class Polygon : public Entity
    {
    public:
        // std::vector<eke::Line *> lines;

    public:
        Polygon(const std::vector<sf::Vector2f> &points, const sf::Color &color, bool closed = false);
        Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed = false);
        ~Polygon();

    public:
        // Experimental
        void Fill(const sf::Color &color);
        // Set poli position by calling Move on each line in linearr
        void SetPosition(const sf::Vector2f &pos);
        // Set poli position by calling Move on each line in linearr
        void SetPosition(const float &posx, const float &posy);
        // Simple ToString :)
        void ToString();
        void PollEvents() override;
        void Update() override;
        void Draw() override;

    private:
        // Basic methods to create sprite and texture from existing verticies
        void InitInitialImgVals();
        void CreateEntity(const sf::Color &color);

    private:
        // Initial entity values
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