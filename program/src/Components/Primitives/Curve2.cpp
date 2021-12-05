#include "Curve2.h"

namespace eke
{
    Curve2::Curve2(const sf::Color &color, std::function<double(double)> func1, std::function<double(double)> func2, double a, double b, int n)
    {
        // float scale = 50.f;
        // sf::Vector2f o;
        // o.x = 800 / 2;
        // o.y = 600 / 2;
        // eke::Curve2 *curve = new eke::Curve2(
        //     sf::Color::Red,
        //     [&scale, &o](double t)
        //     { return scale * t + o.x; },
        //     [&scale, &o](double t)
        //     { return scale * -sin(t) + o.y; },
        //     (-2 * M_PI), (2 * M_PI), 255);
        double t = a;
        double h = (b - a) / n;
        sf::Vector2f v0;
        sf::Vector2f v1;
        v0.x = func1(t);
        v0.y = func2(t);
        while (t <= b)
        {
            t += h;
            v1.x = func1(t);
            v1.y = func2(t);
            this->linearr.push_back(new eke::Line(v0, v1, color));
            v0.x = v1.x;
            v0.y = v1.y;
        }
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            this->linearr[i]->SetColor(color, color);
        }
    }

    Curve2::Curve2(const sf::Color &begincolor, const sf::Color &endcolor, std::function<double(double)> func1, std::function<double(double)> func2, double a, double b, int n)
    {
        // float scale = 50.f;
        // sf::Vector2f o;
        // o.x = 800 / 2;
        // o.y = 600 / 2;
        // eke::Curve2 *curve = new eke::Curve2(
        //     sf::Color::Red, sf::Color::Green,
        //     [&scale, &o](double t)
        //     { return scale * t + o.x; },
        //     [&scale, &o](double t)
        //     { return scale * -sin(t) + o.y; },
        //     (-2 * M_PI), (2 * M_PI), 255);

        double t = a;
        double h = (b - a) / n;
        sf::Vector2f v0;
        sf::Vector2f v1;
        v0.x = func1(t);
        v0.y = func2(t);
        sf::Color beginc = begincolor;
        sf::Color endc = begincolor;
        while (t <= b)
        {
            t += h;
            v1.x = func1(t);
            v1.y = func2(t);
            this->linearr.push_back(new eke::Line(v0, beginc, v1, endc));
            v0.x = v1.x;
            v0.y = v1.y;
            beginc = endc;
            endc.r += (endcolor.r - begincolor.r) / n;
            endc.g += (endcolor.g - begincolor.g) / n;
            endc.b += (endcolor.b - begincolor.b) / n;
        }
    }

    Curve2::~Curve2()
    {
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            delete this->linearr[i];
        }
        this->linearr.clear();
    }

    void Curve2::Draw()
    {
        for (size_t i = 0; i < this->linearr.size(); i++)
        {
            this->linearr[i]->Draw();
        }
    }
}