#include "Polygon.h"

namespace eke
{
    Polygon::Polygon(const std::vector<sf::Vector2f> &points, const std::vector<sf::Color> &colors, bool closed)
    {
        if (points.size() == colors.size())
        {
            for (size_t i = 0; i < points.size() - 1; i++)
            {
                this->linearr.push_back(new eke::Line(points[i], colors[i], points[i + 1], colors[i + 1]));
            }
            if (closed)
            {
                this->linearr.push_back(new eke::Line(this->linearr[this->linearr.size() - 1]->p1, this->linearr[this->linearr.size() - 1]->c2, this->linearr[0]->p0, this->linearr[0]->c1));
            }
        }
        else if (points.size() % 2 == 0 && (points.size() / 2) == colors.size())
        {
            size_t j = 0;
            for (size_t i = 0; i < points.size(); i++)
            {
                this->linearr.push_back(new eke::Line(points[i], colors[j], points[i + 1], colors[j]));
                if (j < colors.size())
                {
                    j++;
                }
            }
            if (closed)
            {
                this->linearr.push_back(new eke::Line(this->linearr[this->linearr.size() - 1]->p1, this->linearr[this->linearr.size() - 1]->c2, this->linearr[0]->p0, this->linearr[0]->c1));
            }
        }
        else if (points.size() % 2 != 0 && ((points.size() / 2) + 1) == colors.size())
        {
            // Impl
        }
        else
        {
            std::cout << "Invalid args!\n";
        }
    }

    void Polygon::Draw()
    {
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            this->linearr[i]->Draw();
        }
    }

    Polygon::~Polygon()
    {
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            delete this->linearr[i];
        }
    }
}