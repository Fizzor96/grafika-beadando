#include "Ellipse2.h"

namespace eke
{
    std::vector<sf::Vector2f> Ellipse2::GenerateEllipse2Positions(float posx, float posy, float r1, float r2)
    {
        float x1 = posx - (r1 / 2);
        float y1 = posy + (r2 / 2);
        float x2 = posx + (r1 / 2);
        float y2 = posy - (r2 / 2);
        double t, a, b, tinc, centx, centy;

        a = fabs(0.5 * (double)(x2 - x1));
        b = fabs(0.5 * (double)(y2 - y1));

        tinc = M_PI * 2 / (a + b);

        centx = (double)((x1 + x2) + .5) * .5;
        centy = (double)((y1 + y2) + .5) * .5;

        std::vector<sf::Vector2f> generated;
        for (t = 0; t < M_PI * 2; t += tinc)
        {
            generated.push_back(sf::Vector2f(centx + a * cos(t), centy - b * sin(t)));
        }
        return generated;
    }

    void Ellipse2::CalculateEllipse(int x1, int y1, int x2, int y2)
    {
        double t, a, b, tinc, centx, centy;
        a = fabs(0.5 * (double)(x2 - x1));
        b = fabs(0.5 * (double)(y2 - y1));
        tinc = M_PI * 2 / (a + b);
        centx = (double)((x1 + x2) + .5) * .5;
        centy = (double)((y1 + y2) + .5) * .5;

        for (t = 0; t < M_PI * 2; t += tinc)
        {
            // std::cout << (centx + a * cos(t)) << " " << (centy - b * sin(t)) << std::endl;
            this->vertexarr.push_back(new eke::Pixel(sf::Vector2f(centx + a * cos(t), centy - b * sin(t))));
            this->positions.push_back(sf::Vector2f(centx + a * cos(t), centy - b * sin(t)));
        }
    }

    Ellipse2::Ellipse2(float posx, float posy, float r1, float r2)
    {
        this->position.x = posx;
        this->position.y = posy;
        this->r1 = r1;
        this->r2 = r2;
        CalculateEllipse(posx - (r1 / 2), posy + (r2 / 2), posx + (r1 / 2), posy - (r2 / 2));
    }

    Ellipse2::~Ellipse2()
    {
    }

    void Ellipse2::Draw()
    {
        for (size_t i = 0; i < this->vertexarr.size(); i++)
        {
            this->vertexarr[i]->Draw();
        }
    }
}