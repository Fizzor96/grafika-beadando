#pragma once

#include <iostream>
#include "Globals.h"
#include <SFML/Graphics.hpp>

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

    // Egyszinu vonal
    Line::Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color)
    {
        this->line = new sf::VertexArray(sf::Lines, 2);
        this->line->append(sf::Vertex(begin, color));
        this->line->append(sf::Vertex(end, color));
    }

    // Szinatmenetes vonal
    Line::Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor)
    {
        this->line = new sf::VertexArray(sf::Lines, 2);
        this->line->append(sf::Vertex(begin, begincolor));
        this->line->append(sf::Vertex(end, endcolor));
    }

    Line::~Line()
    {
        delete this->line;
    }

    void Line::Update()
    {
    }

    void Line::Draw()
    {
        eke::Globals::RenderWindow->draw(*(this->line));
    }

}