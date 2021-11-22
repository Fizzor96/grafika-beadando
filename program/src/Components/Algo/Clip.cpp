#include "Clip.h"

namespace eke
{
    const BYTE Clip::TOP = 1;
    const BYTE Clip::BOTTOM = 2;
    const BYTE Clip::LEFT = 4;
    const BYTE Clip::RIGHT = 8;

    BYTE Clip::OutCode(const sf::FloatRect &rect, const sf::Vector2f &p)
    {
        BYTE code = 0;
        float rectbot = rect.top + rect.height;
        float rectright = rect.left + rect.width;
        if (p.y < rect.top)
        {
            code |= TOP;
        }
        else if (p.y > rectbot)
        {
            code |= BOTTOM;
        }
        if (p.x < rect.left)
        {
            code |= LEFT;
        }
        else if (p.x > rectright)
        {
            code |= RIGHT;
        }
        return code;
    }

    void Clip::CohenShutter(const sf::FloatRect &rect, const eke::Line &line)
    {
        sf::Vector2f p0(line.GetBeginPos());
        sf::Vector2f p1(line.GetEndPos());

        BYTE code0 = OutCode(rect, p0);
        BYTE code1 = OutCode(rect, p1);

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
                BYTE code = code0 != 0 ? code0 : code1;
                float x = 0, y = 0;
                if ((code & TOP) != 0)
                {
                    x = p0.x + (p1.x - p0.x) * (rect.top - p0.y) / (p1.y - p0.y);
                    y = rect.top;
                }
                else if ((code & BOTTOM) != 0)
                {
                    x = p0.x + (p1.x - p0.x) * ((rect.top + rect.height) - p0.y) / (p1.y - p0.y);
                    y = rect.top + rect.height;
                }
                else if ((code & LEFT) != 0)
                {
                    x = rect.left;
                    y = p0.y + (p1.y - p0.y) * (rect.left - p0.x) / (p1.x - p0.x);
                }
                else if ((code & RIGHT) != 0)
                {
                    x = rect.left + rect.width;
                    y = p0.y + (p1.y - p0.y) * ((rect.left + rect.width) - p0.x) / (p1.x - p0.x);
                }

                if (code == code0)
                {
                    p0.x = x;
                    p0.y = y;
                    code0 = OutCode(rect, p0);
                }
                else
                {
                    p1.x = x;
                    p1.y = y;
                    code1 = OutCode(rect, p1);
                }
            }
        }
        if (accept)
        {
            // eke::Line(p0, line.GetColorByVertexPos(p0), p1, line.GetColorByVertexPos(p1)).Draw();
            eke::Line(p0, line.GetBeginColor(), p1, line.GetEndColor()).Draw();
        }
    }

    void Clip::Clipp(const sf::FloatRect &rect, const eke::Line &line)
    {
        for (size_t i = 0; i < line.vertexarr.size(); i++)
        {
            if ((line.vertexarr[i]->GetPosition().x) >= rect.left && (line.vertexarr[i]->GetPosition().x) <= (rect.left + rect.width) && (int)(line.vertexarr[i]->GetPosition().y) >= rect.top && (line.vertexarr[i]->GetPosition().y) <= (rect.top + rect.height))
            {
                line.vertexarr[i]->Draw();
            }
        }
    }
}
