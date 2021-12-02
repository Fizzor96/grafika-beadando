#include "Rectangle.h"

namespace eke
{
    Rectangle::Rectangle(const sf::Vector2f &size, const sf::Vector2f &centerpos, const sf::Color &color)
    {
        sf::Vector2f startpos;
        startpos.x = centerpos.x - size.x / 2;
        startpos.y = centerpos.y - size.y / 2;
        this->lines.push_back(new eke::Line(startpos, sf::Vector2f(startpos.x + size.x, startpos.y), color));
        this->lines.push_back(new eke::Line(this->lines[0]->GetEndPos(), sf::Vector2f(this->lines[0]->GetEndPos().x, this->lines[0]->GetEndPos().y + size.y), color));
        this->lines.push_back(new eke::Line(this->lines[1]->GetEndPos(), sf::Vector2f(this->lines[1]->GetEndPos().x - size.x, this->lines[1]->GetEndPos().y), color));
        this->lines.push_back(new eke::Line(this->lines[2]->GetEndPos(), sf::Vector2f(this->lines[0]->GetBeginPos()), color));
    }

    Rectangle::Rectangle(const float &width, const float &height, const float &centerx, const float &centery, const sf::Color &color)
    {
        sf::Vector2f startpos;
        startpos.x = centerx - width / 2;
        startpos.y = centery - height / 2;
        this->lines.push_back(new eke::Line(startpos, sf::Vector2f(startpos.x + width, startpos.y), color));
        this->lines.push_back(new eke::Line(this->lines[0]->GetEndPos(), sf::Vector2f(this->lines[0]->GetEndPos().x, this->lines[0]->GetEndPos().y + height), color));
        this->lines.push_back(new eke::Line(this->lines[1]->GetEndPos(), sf::Vector2f(this->lines[1]->GetEndPos().x - width, this->lines[1]->GetEndPos().y), color));
        this->lines.push_back(new eke::Line(this->lines[2]->GetEndPos(), sf::Vector2f(this->lines[0]->GetBeginPos()), color));
    }

    Rectangle::~Rectangle()
    {
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            delete this->lines[i];
        }
        this->lines.clear();
    }

    void Rectangle::Draw()
    {
        for (size_t i = 0; i < lines.size(); i++)
        {
            this->lines[i]->Draw();
        }
    }
}