#pragma once

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Globals.h"

namespace eke
{
    class Ellipse : public sf::Shape
    {
    private:
        sf::Vector2f m_radius;

    public:
        explicit Ellipse(const sf::Vector2f &radius = sf::Vector2f(0, 0));
        void setRadius(const sf::Vector2f &radius);
        const sf::Vector2f &getRadius() const;
        virtual size_t getPointCount() const;
        virtual sf::Vector2f getPoint(unsigned int index) const;
        void Draw();
        ~Ellipse();

        Ellipse() = delete;
        Ellipse(const eke::Ellipse &other) = delete;
        Ellipse(Ellipse &&other) = delete;
    };

    Ellipse::Ellipse(const sf::Vector2f &radius) : m_radius(radius)
    {
        update();
    }

    void Ellipse::setRadius(const sf::Vector2f &radius)
    {
        m_radius = radius;
        update();
    }

    const sf::Vector2f &Ellipse::getRadius() const
    {
        return m_radius;
    }

    size_t Ellipse::getPointCount() const
    {
        return this->getPointCount();
    }

    sf::Vector2f Ellipse::getPoint(unsigned int index) const
    {
        float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

    Ellipse::~Ellipse()
    {
    }

    void Ellipse::Draw()
    {
        eke::Globals::RenderWindow->draw(*(this));
    }
}