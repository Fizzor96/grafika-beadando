#include "Clip.h"

namespace eke
{
    // typedef unsigned int BYTE;

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

    void Clip::Clipp(const sf::FloatRect &rect, sf::Vector2f p0, sf::Vector2f p1)
    {
        BYTE code0 = OutCode(rect, p0);
        BYTE code1 = OutCode(rect, p1);

        bool accept = false;

        while (true)
        {
            if ((int)(code0 | code1) == 0)
            {
                accept = true;
                break;
            }
            else if ((int)(code0 & code1) != 0)
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
            eke::Line(p0, p1, sf::Color::Yellow).Draw();
        }
    }

    void Clip::Clipp2(const sf::FloatRect &rect, const eke::Line &line)
    {
        // int rectleft, recttop, rectright, rectbottom;
        // rectleft = rect.left;
        // recttop = rect.top;
        // rectright = rect.left + rect.width;
        // rectbottom = rect.top + rect.height;
        // int posx, posy;

        // std::vector<sf::Vector2f> inboundcoords;
        for (size_t i = 0; i < line.vertexarr.size(); i++)
        {
            // posx = (int)((*line.vertexarr)[i]->GetPosition().x);
            // posy = (int)((*line.vertexarr)[i]->GetPosition().y);

            if ((line.vertexarr[i]->pos.x) >= rect.left && (line.vertexarr[i]->pos.x) <= (rect.left + rect.width) && (int)(line.vertexarr[i]->pos.y) >= rect.top && (line.vertexarr[i]->pos.y) <= (rect.top + rect.height))
            {
                line.vertexarr[i]->Draw();
                // inboundcoords.push_back(sf::Vector2f((*line.vertexarr)[i]->GetPosition()));
            }
        }
        // if (inboundcoords.size() > 0)
        // {
        //     eke::Line(sf::Vector2f(inboundcoords.front().x, inboundcoords.front().y), sf::Color(line.c1), sf::Vector2f(inboundcoords.back().x, inboundcoords.back().y), sf::Color(line.c2)).Draw();
        // }
    }

    void Clip::Clipp3(const sf::FloatRect &rect, const eke::Line &line)
    {
        sf::Vector2f p0(line.p0);
        sf::Vector2f p1(line.p1);

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
            if (line.GetPixelColorByPos(p0) != nullptr)
            {
                eke::Line(p0, *line.GetPixelColorByPos(p0), p1, *line.GetPixelColorByPos(p1)).Draw();
            }
            else
            {
                eke::Line(p0, line.c1, p1, line.c2).Draw();
            }
        }
    }
}
