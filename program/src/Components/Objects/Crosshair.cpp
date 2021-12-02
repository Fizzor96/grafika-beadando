#include "Crosshair.h"

namespace eke
{
    Crosshair::Crosshair(const sf::Vector2f &size, const bool &isgrabbed)
    {
        this->posindicator = 0;
        this->sprite = nullptr;
        this->texture = nullptr;
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
        delete this->sprite;
        delete this->texture;
    }

    void Crosshair::SetTrack(const std::vector<sf::Vector2f> &track)
    {
        this->track = track;
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
        else
        {
            rs.setPosition(this->track[this->posindicator]);
        }
    }

    void Crosshair::Draw()
    {
        eke::Globals::RenderWindow->draw(this->rs);
    }
}