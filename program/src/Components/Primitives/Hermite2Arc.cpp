#include "Hermite2Arc.h"

namespace eke
{
    double Hermite::H0(double t)
    {
        return 2 * t * t * t - 3 * t * t + 1;
    }

    double Hermite::H1(double t)
    {
        return -2 * t * t * t + 3 * t * t;
    }

    double Hermite::H2(double t)
    {
        return t * t * t - 2 * t * t + t;
    }

    double Hermite::H3(double t)
    {
        return t * t * t - t * t;
    }

    Hermite::Hermite(const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &q0, const sf::Vector2f &q1, const double &weight)
    {
        this->p0 = p0;
        this->p1 = p1;
        this->q0 = q0;
        this->q1 = q1;
        this->weight = weight;
    }

    Hermite2Arc::Hermite2Arc(const sf::Color &color, const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &q0, const sf::Vector2f &q1, int n)
    {
        // sf::Vector2f p0(200, 300);
        // sf::Vector2f q0(400, 50);
        // sf::Vector2f p1(500, 250);
        // sf::Vector2f q1(600, 450);
        // eke::Hermite2 *curve = new eke::Hermite2(sf::Color::Green, p0, p1, (2.f * (q0 - p0)), (2.f * (q1 - p1)), 255);
        // eke::Line line1(p0, q0, sf::Color::Cyan);
        // eke::Line line2(p1, q1, sf::Color::Cyan);

        this->curve = new eke::Curve2(
            color,
            [&p0, &p1, &q0, &q1](double t)
            { return eke::Hermite::H0(t) * p0.x + eke::Hermite::H1(t) * p1.x + eke::Hermite::H2(t) * q0.x + eke::Hermite::H3(t) * q1.x; },
            [&p0, &p1, &q0, &q1](double t)
            { return eke::Hermite::H0(t) * p0.y + eke::Hermite::H1(t) * p1.y + eke::Hermite::H2(t) * q0.y + eke::Hermite::H3(t) * q1.y; },
            0, 1, n);
    }

    Hermite2Arc::Hermite2Arc(const sf::Color &color, const Hermite &arc, int n)
    {
        this->curve = new eke::Curve2(
            color,
            [&arc](double t)
            { return eke::Hermite::H0(t) * arc.p0.x + eke::Hermite::H1(t) * arc.p1.x + eke::Hermite::H2(t) * arc.q0.x + eke::Hermite::H3(t) * arc.q1.x; },
            [&arc](double t)
            { return eke::Hermite::H0(t) * arc.p0.y + eke::Hermite::H1(t) * arc.p1.y + eke::Hermite::H2(t) * arc.q0.y + eke::Hermite::H3(t) * arc.q1.y; },
            0, 1, n);
    }

    Hermite2Arc::~Hermite2Arc()
    {
        delete curve;
    }

    void Hermite2Arc::Draw()
    {
        this->curve->Draw();
    }
}