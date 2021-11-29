#include "Ellipse.h"

namespace eke
{
    Ellipse::Ellipse(int rx, int ry, int xc, int yc, sf::Color color)
    {
        float dx, dy, d1, d2, x, y;
        x = 0;
        y = ry;
        d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;
        while (dx < dy)
        {
            this->vertexarr.push_back(new eke::Pixel(x + xc, y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(-x + xc, y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(x + xc, -y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(-x + xc, -y + yc, color));
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
            this->vertexarr.push_back(new eke::Pixel(x + xc, y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(-x + xc, y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(x + xc, -y + yc, color));
            this->vertexarr.push_back(new eke::Pixel(-x + xc, -y + yc, color));
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
    }

    void Ellipse::Draw()
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            this->vertexarr[i]->Draw();
        }
    }

}