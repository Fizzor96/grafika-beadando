#pragma once

#include "Engine/Globals.h"
#include "Engine.h"
#include <math.h>

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
        // void Draw();
        ~Ellipse();

        Ellipse() = delete;
        Ellipse(const eke::Ellipse &other) = delete;
        Ellipse(Ellipse &&other) = delete;
    };
}