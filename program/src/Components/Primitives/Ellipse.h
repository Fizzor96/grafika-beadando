#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP 1

#include <SFML/Graphics.hpp>
#include "Core/Globals.h"
#include <math.h>

namespace eke
{
    class Ellipse : public sf::Shape
    {
    private:
        sf::Vector2f m_radius;

    public:
        Ellipse(const sf::Vector2f &radius = sf::Vector2f(0, 0));
        ~Ellipse();
        void setRadius(const sf::Vector2f &radius);
        const sf::Vector2f &getRadius() const;
        sf::Vector2f getCenter() const;

        void Draw();

    private:
        std::size_t getPointCount() const override;
        sf::Vector2f getPoint(std::size_t index) const;

    public:
        Ellipse() = delete;
        Ellipse(const eke::Ellipse &other) = delete;
        Ellipse(Ellipse &&other) = delete;
    };
}

#endif