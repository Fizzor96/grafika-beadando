#include "Crosshair.h"

namespace eke
{
    Crosshair::Crosshair(const sf::Vector2f &size, const bool &isgrabbed)
    {
        this->isgrabbed = isgrabbed;
        rs.setSize(size);
        rs.setPosition(sf::Vector2f(100, 100));
        rs.setOrigin(rs.getSize().x / 2, rs.getSize().y / 2);
        rs.setFillColor(sf::Color(73, 230, 107, 100));
        rs.setOutlineThickness(1.f);
        rs.setOutlineColor(sf::Color::Black);
    }

    sf::FloatRect Crosshair::GetGlobalBounds() const
    {
        return this->rs.getGlobalBounds();
    }

    Crosshair::~Crosshair()
    {
    }

    void Crosshair::PollEvents()
    {
    }

    void Crosshair::Update()
    {
        if (isgrabbed)
        {
            rs.setPosition(eke::Globals::MousePosition);
        }
    }

    void Crosshair::Draw()
    {
        eke::Globals::RenderWindow->draw(this->rs);
    }
}