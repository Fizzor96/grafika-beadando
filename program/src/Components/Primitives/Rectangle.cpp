#include "Rectangle.h"

namespace eke
{
    Rectangle::Rectangle(const sf::Vector2f &size, const sf::Vector2f &centerpos, const sf::Color &color)
    {
        this->position.x = centerpos.x;
        this->position.y = centerpos.y;
        this->boundingbox.left = centerpos.x - size.x / 2;
        this->boundingbox.top = centerpos.y - size.y / 2;
        this->boundingbox.width = size.x;
        this->boundingbox.height = size.y;
        this->texture = nullptr;
        this->sprite = nullptr;
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
        this->boundingbox.left = centerx - width / 2;
        this->boundingbox.top = centery - height / 2;
        this->boundingbox.width = width;
        this->boundingbox.height = height;
        this->texture = nullptr;
        this->sprite = nullptr;
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

    sf::Vector2f Rectangle::GetPosition() const
    {
        sf::Vector2f pos;
        pos.x = this->boundingbox.left;
        pos.y = this->boundingbox.top;
        return pos;
    }

    sf::Vector2f Rectangle::GetSize() const
    {
        sf::Vector2f size;
        size.x = this->boundingbox.width;
        size.y = this->boundingbox.height;
        return size;
    }

    void Rectangle::SetPosition(const float &posx, const float &posy)
    {
        sf::Vector2f diff;
        if (this->position.x != posx && this->position.y != posy)
        {
            diff.x = posx - this->position.x;
            diff.y = posy - this->position.y;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
        }
        this->position.x = posx;
        this->position.y = posy;
        this->boundingbox.left += diff.x;
        this->boundingbox.top += diff.y;
    }

    void Rectangle::SetPosition(const sf::Vector2f &pos)
    {
        sf::Vector2f diff;
        if (this->position != pos)
        {
            diff.x = pos.x - this->position.x;
            diff.y = pos.y - this->position.y;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
        }
        this->position.x = pos.x;
        this->position.y = pos.y;
        this->boundingbox.left += diff.x;
        this->boundingbox.top += diff.y;
    }

    sf::FloatRect Rectangle::GetGlobalBounds() const
    {
        return this->boundingbox;
    }

    void Rectangle::Draw()
    {
        for (size_t i = 0; i < lines.size(); i++)
        {
            this->lines[i]->Draw();
        }
    }

    void Rectangle::PollEvents()
    {
    }

    void Rectangle::Update()
    {
    }
}