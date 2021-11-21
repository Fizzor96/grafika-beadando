#include "Ellipse.h"

namespace eke
{
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

    std::size_t Ellipse::getPointCount() const
    {
        return 30;
    }

    sf::Vector2f Ellipse::getPoint(std::size_t index) const
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

    sf::Vector2f Ellipse::getCenter() const
    {

        return sf::Vector2f(this->getPosition().x + this->getRadius().x, this->getPosition().y + this->getRadius().y);
    }
}