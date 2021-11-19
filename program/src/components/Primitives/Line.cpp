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

    void Line::SetPosition(const sf::Vector2f &pos)
    {
        sf::Vector2f diff;

        diff.x = pos.x - this->vertexarr[0]->pos.x;
        diff.y = pos.y - this->vertexarr[0]->pos.y;

        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            auto currpix = this->vertexarr[i];
            this->vertexarr[i]->pos = currpix->pos + diff;
        }

        this->p0.x = this->vertexarr[0]->pos.x;
        this->p0.y = this->vertexarr[0]->pos.y;
        this->p1.x = this->vertexarr[this->vertexarr.size() - 1]->pos.x;
        this->p1.y = this->vertexarr[this->vertexarr.size() - 1]->pos.y;
    }

    sf::Color *Line::GetPixelColorByPos(const sf::Vector2f &pixelpos) const
    {
        if (this->vertexarr.size() > 0)
        {
            for (size_t i = 0; i < this->vertexarr.size(); i++)
            {
                if (this->vertexarr[i]->pos.x == pixelpos.x && this->vertexarr[i]->pos.y == pixelpos.y)
                {
                    return new sf::Color(this->vertexarr[i]->color);
                }
                else
                {
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    void Line::SetThickness(const float &factor)
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            this->vertexarr[i]->SetScale(sf::Vector2f(factor, factor));
        }
        this->thickness = factor;
    }

    float Line::GetThickness() const
    {
        return this->thickness;
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