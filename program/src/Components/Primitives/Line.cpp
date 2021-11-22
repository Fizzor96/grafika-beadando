#include "Line.h"

namespace eke
{
    // Egyszinu vonal
    Line::Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color)
    {
        this->p0.x = begin.x;
        this->p0.y = begin.y;
        this->p1.x = end.x;
        this->p1.y = end.y;
        this->c1 = color;
        this->c2 = color;

        // std::cout << "class: x1=" << this->p0->x << ", y1=" << this->p0->y;
        // std::cout << " x2=" << this->p1->x << ", y2=" << this->p1->y << "\n";

        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0.x;
        float y = p0.y;

        this->vertexarr.push_back(new eke::Pixel(p0));
        this->positions.push_back(sf::Vector2f(p0.x, p0.y));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(x, y), color));
            this->positions.push_back(sf::Vector2f(x, y));
        }
    }

    Line::Line(const float &beginx, const float &beginy, const float &endx, const float &endy, const sf::Color &color)
    {
        this->p0.x = beginx;
        this->p0.y = beginy;
        this->p1.x = endx;
        this->p1.y = endy;
        this->c1 = color;
        this->c2 = color;

        // std::cout << "class: x1=" << this->p0->x << ", y1=" << this->p0->y;
        // std::cout << " x2=" << this->p1->x << ", y2=" << this->p1->y << "\n";

        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0.x;
        float y = p0.y;

        this->vertexarr.push_back(new eke::Pixel(p0));
        this->positions.push_back(sf::Vector2f(p0.x, p0.y));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(x, y), color));
            this->positions.push_back(sf::Vector2f(x, y));
        }
    }

    // Szinatmenetes vonal
    Line::Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor)
    {
        this->p0.x = begin.x;
        this->p0.y = begin.y;
        this->p1.x = end.x;
        this->p1.y = end.y;
        this->c1 = begincolor;
        this->c2 = endcolor;
        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0.x;
        float y = p0.y;

        float incR = (c2.r - c1.r) / length;
        float incG = (c2.g - c1.g) / length;
        float incB = (c2.b - c1.b) / length;
        float R = c1.r, G = c1.g, B = c1.b;

        this->vertexarr.push_back(new eke::Pixel(p0, sf::Color(R, G, B, c1.a)));
        this->positions.push_back(sf::Vector2f(p0.x, p0.y));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            R += incR;
            G += incG;
            B += incB;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(x, y), sf::Color(R, G, B, c2.a)));
            this->positions.push_back(sf::Vector2f(x, y));
        }
    }

    Line::Line(const float &beginx, const float &beginy, const sf::Color &begincolor, const float &endx, const float &endy, const sf::Color &endcolor)
    {
        this->p0.x = beginx;
        this->p0.y = beginy;
        this->p1.x = endx;
        this->p1.y = endy;
        this->c1 = begincolor;
        this->c2 = endcolor;
        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0.x;
        float y = p0.y;

        float incR = (c2.r - c1.r) / length;
        float incG = (c2.g - c1.g) / length;
        float incB = (c2.b - c1.b) / length;
        float R = c1.r, G = c1.g, B = c1.b;

        this->vertexarr.push_back(new eke::Pixel(p0, sf::Color(R, G, B, c1.a)));
        this->positions.push_back(sf::Vector2f(p0.x, p0.y));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            R += incR;
            G += incG;
            B += incB;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(x, y), sf::Color(R, G, B, c2.a)));
            this->positions.push_back(sf::Vector2f(x, y));
        }
    }

    void Line::Move(const float &diffx, const float &diffy)
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            this->vertexarr[i]->SetPosition(sf::Vector2f(this->vertexarr[i]->GetPosition().x + diffx, this->vertexarr[i]->GetPosition().y + diffy));
        }
        this->p0.x = this->vertexarr[0]->GetPosition().x;
        this->p0.y = this->vertexarr[0]->GetPosition().y;
        this->p1.x = (this->vertexarr[this->vertexarr.size() - 1])->GetPosition().x;
        this->p1.y = (this->vertexarr[this->vertexarr.size() - 1])->GetPosition().y;
    }

    void Line::SetPosition(const sf::Vector2f &pos)
    {
        sf::Vector2f diff;

        diff.x = pos.x - this->vertexarr[0]->GetPosition().x;
        diff.y = pos.y - this->vertexarr[0]->GetPosition().y;

        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            auto currpix = this->vertexarr[i];
            this->vertexarr[i]->SetPosition(this->vertexarr[i]->GetPosition() + diff);
        }

        this->p0.x = this->vertexarr[0]->GetPosition().x;
        this->p0.y = this->vertexarr[0]->GetPosition().y;
        this->p1.x = this->vertexarr[this->vertexarr.size() - 1]->GetPosition().x;
        this->p1.y = this->vertexarr[this->vertexarr.size() - 1]->GetPosition().y;
    }

    void Line::SetPosition(const float &posx, const float &posy)
    {
        sf::Vector2f diff;

        diff.x = posx - this->vertexarr[0]->GetPosition().x;
        diff.y = posy - this->vertexarr[0]->GetPosition().y;

        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            auto currpix = this->vertexarr[i];
            this->vertexarr[i]->SetPosition(this->vertexarr[i]->GetPosition() + diff);
        }

        this->p0.x = this->vertexarr[0]->GetPosition().x;
        this->p0.y = this->vertexarr[0]->GetPosition().y;
        this->p1.x = this->vertexarr[this->vertexarr.size() - 1]->GetPosition().x;
        this->p1.y = this->vertexarr[this->vertexarr.size() - 1]->GetPosition().y;
    }

    void Line::SetThickness(const float &factor)
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            this->vertexarr[i]->SetScale(sf::Vector2f(factor, factor));
        }
        this->thickness = factor;
    }

    void Line::SetColor(const sf::Color &colorbegin, const sf::Color &colorend)
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            delete this->vertexarr[i];
        }
        this->vertexarr.clear();

        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0.x;
        float y = p0.y;

        float incR = (c2.r - c1.r) / length;
        float incG = (c2.g - c1.g) / length;
        float incB = (c2.b - c1.b) / length;
        float R = c1.r, G = c1.g, B = c1.b;

        this->vertexarr.push_back(new eke::Pixel(p0, sf::Color(R, G, B, c1.a)));
        // this->positions.push_back(sf::Vector2f(p0.x, p0.y));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            R += incR;
            G += incG;
            B += incB;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(x, y), sf::Color(R, G, B, c2.a)));
            // this->positions.push_back(sf::Vector2f(x, y));
        }
    }

    float Line::GetThickness() const
    {
        return this->thickness;
    }

    sf::Vector2f Line::GetBeginPos() const
    {
        return p0;
    }

    sf::Vector2f Line::GetEndPos() const
    {
        return p1;
    }

    sf::Color Line::GetBeginColor() const
    {
        return c1;
    }

    sf::Color Line::GetEndColor() const
    {
        return c2;
    }

    sf::Color Line::GetColorByVertexPos(const sf::Vector2f &pos) const
    {
        sf::Color color;
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            if (this->vertexarr[i]->GetPosition() == pos)
            {
                color = this->vertexarr[i]->GetColor();
            }
        }
        return color;
    }

    Line::~Line()
    {
        for (size_t i = 0; i < vertexarr.size(); i++)
        {
            delete vertexarr[i];
        }
    }

    void Line::Draw()
    {
        for (size_t i = 0; i < vertexarr.size(); i++)
        {
            vertexarr[i]->Draw();
        }
    }
}