#include "Ellipse.h"

namespace eke
{
    Ellipse::Ellipse(int rx, int ry, int xc, int yc, sf::Color color)
    {
        this->texture = nullptr;
        this->sprite = nullptr;

        this->center.x = xc;
        this->center.y = yc;

        float dx, dy, d1, d2, x, y;
        x = 0;
        y = ry;
        d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;
        while (dx < dy)
        {
            // 2
            this->vertexarr.push_back(new eke::Pixel(x + xc, y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(x + xc, y + yc), sf::Vector2f(x + xc, y + yc), color));
            // 3
            this->vertexarr.push_back(new eke::Pixel(-x + xc, y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(-x + xc, y + yc), sf::Vector2f(-x + xc, y + yc), color));
            // 6
            this->vertexarr.push_back(new eke::Pixel(x + xc, -y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(x + xc, -y + yc), sf::Vector2f(x + xc, -y + yc), color));
            // 7
            this->vertexarr.push_back(new eke::Pixel(-x + xc, -y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(-x + xc, -y + yc), sf::Vector2f(-x + xc, -y + yc), color));
            if (d1 < 0)
            {
                x++;
                dx = dx + (2 * ry * ry);
                d1 = d1 + dx + (ry * ry);
            }
            else
            {
                x++;
                y--;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d1 = d1 + dx - dy + (ry * ry);
            }
        }
        d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
             ((rx * rx) * ((y - 1) * (y - 1))) -
             (rx * rx * ry * ry);
        while (y >= 0)
        {
            // 1
            this->vertexarr.push_back(new eke::Pixel(x + xc, y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(x + xc, y + yc), sf::Vector2f(x + xc, y + yc), color));
            // 4
            this->vertexarr.push_back(new eke::Pixel(-x + xc, y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(-x + xc, y + yc), sf::Vector2f(-x + xc, y + yc), color));
            // 5
            this->vertexarr.push_back(new eke::Pixel(-x + xc, -y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(-x + xc, -y + yc), sf::Vector2f(-x + xc, -y + yc), color));
            // 8
            this->vertexarr.push_back(new eke::Pixel(x + xc, -y + yc, color));
            this->lines.push_back(new eke::Line(sf::Vector2f(x + xc, -y + yc), sf::Vector2f(x + xc, -y + yc), color));

            if (d2 > 0)
            {
                y--;
                dy = dy - (2 * rx * rx);
                d2 = d2 + (rx * rx) - dy;
            }
            else
            {
                y--;
                x++;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d2 = d2 + dx - dy + (rx * rx);
            }
        }
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            for (size_t j = i + 1; j < this->vertexarr.size(); j++)
            {
                if (this->vertexarr[i] == this->vertexarr[j])
                {
                    delete this->vertexarr[i];
                    this->vertexarr.erase(this->vertexarr.begin() + i);
                }
            }
        }
    }

    Ellipse::~Ellipse()
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            delete this->vertexarr[i];
        }
        this->vertexarr.clear();

        for (size_t i = 0; i < this->lines.size(); i++)
        {
            delete this->lines[i];
        }
        this->lines.clear();
    }

    void Ellipse::SetPosition(const float &x, const float &y)
    {
        if (this->center.x != x && this->center.y != y)
        {
            sf::Vector2f diff;
            diff.x = x - this->center.x;
            diff.y = y - this->center.y;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
            this->center.x = x;
            this->center.y = y;
        }
    }

    void Ellipse::SetPosition(const sf::Vector2f pos)
    {
        if (this->center != pos)
        {
            sf::Vector2f diff;
            diff.x = pos.x - this->center.x;
            diff.y = pos.y - this->center.y;
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                this->lines[i]->Move(diff.x, diff.y);
            }
            this->center.x = pos.x;
            this->center.y = pos.y;
        }
    }

    void Ellipse::PollEvents()
    {
    }

    void Ellipse::Update()
    {
    }

    void Ellipse::Draw()
    {
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            this->lines[i]->Draw();
        }

        // for (size_t i = 0; i < this->vertexarr.size(); i++)
        // {
        //     this->vertexarr[i]->Draw();
        // }
    }

    // void Ellipse::Fill()
    // {
    //     for (size_t i = 0; i < this->lines.size() - 1; i++)
    //     {
    //         for (size_t j = i + 1; j < this->lines.size(); j++)
    //         {
    //             if (this->lines[i]->GetBeginPos().y == this->lines[j]->GetBeginPos().y)
    //             {
    //                 this->filled.push_back(new eke::Line(sf::Vector2f(this->lines[i]->GetBeginPos()), sf::Vector2f(this->lines[j]->GetBeginPos()), this->lines[i]->GetBeginColor()));
    //             }
    //         }
    //     }
    // }
}