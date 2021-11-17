#include "Clip.h"

namespace eke
{
    const unsigned int Clip::TOP = 1;
    const unsigned int Clip::BOTTOM = 2;
    const unsigned int Clip::LEFT = 4;
    const unsigned int Clip::RIGHT = 8;

    unsigned int Clip::OutCode(const sf::IntRect &rect, const sf::Vector2f &p)
    {
        unsigned int code = 0;
        if (p.y < rect.top)
        {
            code |= TOP;
        }
        else if (p.y > (rect.top + rect.height))
        {
            code |= BOTTOM;
        }
        if (p.x < rect.left)
        {
            code |= LEFT;
        }
        else if (p.x > (rect.left + rect.width))
        {
            code |= RIGHT;
        }
        return code;
    }

    void Clip::Clipp(const sf::IntRect &rect, eke::Line *line)
    {
        std::cout << "clip: x1=" << line->p0->x << ", y1=" << line->p0->y;
        std::cout << "clip: x2=" << line->p1->x << ", y2=" << line->p1->y << "\n";
        sf::Vector2f &v1 = *line->p0;
        sf::Vector2f &v2 = *line->p1;
        unsigned int code0 = OutCode(rect, v1);
        unsigned int code1 = OutCode(rect, v2);

        bool accept = false;

        while (true)
        {
            if ((code0 | code1) == 0)
            {
                accept = true;
                break;
            }
            else if ((code0 & code1) != 0)
            {
                break;
            }
            else
            {
                unsigned int code = code0 != 0 ? code0 : code1;
                float x = 0, y = 0;
                if ((code & TOP) != 0)
                {
                    x = v1.x + (v2.x - v1.x) * (rect.top - v1.y) / (v2.y - v1.y);
                    y = rect.top;
                }
                else if ((code & BOTTOM) != 0)
                {
                    x = v1.x + (v2.x - v1.x) * ((rect.top + rect.height) - v1.y) / (v2.y - v1.y);
                    y = (rect.top + rect.height);
                }
                else if ((code & LEFT) != 0)
                {
                    x = rect.left;
                    y = v1.y + (v2.y - v1.y) * (rect.left - v1.x) / (v2.x - v1.x);
                }
                else if ((code & RIGHT) != 0)
                {
                    x = (rect.left + rect.width);
                    y = v1.y + (v2.y - v1.y) * ((rect.left + rect.width) - v1.x) / (v2.x - v1.x);
                }

                if (code == code0)
                {
                    v1.x = x;
                    v1.y = y;
                    code0 = OutCode(rect, v1);
                }
                else
                {
                    v2.x = x;
                    v2.y = y;
                    code1 = OutCode(rect, v2);
                }
            }
        }
        if (accept)
        {
            eke::Line templine(sf::Vector2f(v1), sf::Vector2f(v2), sf::Color::White);
            templine.Draw();
        }
    }
}
