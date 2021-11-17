#include "Line.h"

namespace eke
{
    // Egyszinu vonal
    Line::Line(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color)
    {
        this->vertexarr = new std::vector<eke::Pixel *>();
        this->p0 = new sf::Vector2f(begin.x, begin.y);
        this->p1 = new sf::Vector2f(end.x, end.y);
        this->c1 = color;
        this->c2 = color;

        // std::cout << "class: x1=" << this->p0->x << ", y1=" << this->p0->y;
        // std::cout << " x2=" << this->p1->x << ", y2=" << this->p1->y << "\n";

        float dx = p1->x - p0->x;
        float dy = p1->y - p0->y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0->x;
        float y = p0->y;

        this->vertexarr->push_back(new eke::Pixel(*p0));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            this->vertexarr->push_back(new eke::Pixel(sf::Vector2f(x, y)));
        }
    }

    // Szinatmenetes vonal
    Line::Line(const sf::Vector2f &begin, const sf::Color &begincolor, const sf::Vector2f &end, const sf::Color &endcolor)
    {
        this->vertexarr = new std::vector<eke::Pixel *>();
        this->p0 = new sf::Vector2f(begin);
        this->p1 = new sf::Vector2f(end);
        this->c1 = begincolor;
        this->c2 = endcolor;
        float dx = p1->x - p0->x;
        float dy = p1->y - p0->y;
        float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float incX = dx / length;
        float incY = dy / length;
        float x = p0->x;
        float y = p0->y;

        float incR = (c2.r - c1.r) / length;
        float incG = (c2.g - c1.g) / length;
        float incB = (c2.b - c1.b) / length;
        float R = c1.r, G = c1.g, B = c1.b;

        this->vertexarr->push_back(new eke::Pixel(*p0, sf::Color(R, G, B, c1.a)));
        for (size_t i = 0; i < length; i++)
        {
            x += incX;
            y += incY;
            R += incR;
            G += incG;
            B += incB;
            this->vertexarr->push_back(new eke::Pixel(sf::Vector2f(x, y), sf::Color(R, G, B, c2.a)));
        }
    }

    std::vector<eke::Pixel *> Line::GetVerticies() const
    {
        return *this->vertexarr;
    }

    size_t Line::GetVertexCount() const
    {
        return this->vertexarr->size();
    }

    Line::~Line()
    {
        for (size_t i = 0; i < vertexarr->size(); i++)
        {
            delete (*vertexarr)[i];
        }
        delete this->vertexarr;
    }

    void Line::Draw()
    {
        for (size_t i = 0; i < vertexarr->size(); i++)
        {
            (*vertexarr)[i]->Draw();
        }
    }
}