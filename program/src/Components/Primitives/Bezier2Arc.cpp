#include "Bezier2Arc.h"

namespace eke
{
    Bezier::Bezier(const double &p)
    {
        this->p = p;
        this->p0 = sf::Vector2f(0, 0);
        this->p1 = sf::Vector2f(0, 0);
        this->p2 = sf::Vector2f(0, 0);
        this->p3 = sf::Vector2f(0, 0);
    }

    Bezier::Bezier(const sf::Vector2f &p0, const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3, const double &p)
    {
        this->p = p;
        this->p0 = p0;
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }

    double Bezier::B0(const double &t, const double &p)
    {
        return (1 - t) * (1 - t) * (1 + (2 - p) * t);
    }

    double Bezier::B1(const double &t, const double &p)
    {
        return p * t * (1 - t) * (1 - t);
    }

    double Bezier::B2(const double &t, const double &p)
    {
        return p * t * t * (1 - t);
    }

    double Bezier::B3(const double &t, const double &p)
    {
        return t * t * (3 - p + (p - 2) * t);
    }

    double Bezier::BezierBernstein(const double &t, const int &n, const int &i)
    {
        return eke::Binomial().GetBinom(n, i) * pow(1.0 - t, n - i) * pow(t, i);
    }

    Bezier2Arc::Bezier2Arc(const sf::Color &color)
    {
        // std::cout << vectors[vectors.size() - 1].x << " " << vectors[vectors.size() - 1].y << " " << vectors.size() << std::endl;
        this->color = new sf::Color(color);
        this->vectorsize = 0;
        this->curve = nullptr;
    }

    Bezier2Arc::Bezier2Arc(const sf::Color &color, const Bezier &arc)
    {
        this->vectorsize = 0;
        this->color = new sf::Color(color);
        this->curve = new eke::Curve2(
            color, [&arc](double t)
            { return Bezier::B0(t, arc.p) * arc.p0.x + Bezier::B1(t, arc.p) * arc.p1.x + Bezier::B2(t, arc.p) * arc.p2.x + Bezier::B3(t, arc.p) * arc.p3.x; },
            [&arc](double t)
            { return Bezier::B0(t, arc.p) * arc.p0.y + Bezier::B1(t, arc.p) * arc.p1.y + Bezier::B2(t, arc.p) * arc.p2.y + Bezier::B3(t, arc.p) * arc.p3.y; },
            0, 1);
    }

    Bezier2Arc::Bezier2Arc(const sf::Color &color, const std::vector<sf::Vector2f> &vectors)
    {
        // std::cout << vectors[vectors.size() - 1].x << " " << vectors[vectors.size() - 1].y << " " << vectors.size() << std::endl;
        this->color = new sf::Color(color);
        this->vectorsize = 0;
        this->curve = nullptr;
        double t = 0.0;
        double h = 1.0 / 100;
        int n = vectors.size() - 1;
        sf::Vector2f v0 = sf::Vector2f(0.f, 0.f);
        for (int i = 0; i <= n; i++)
        {
            double Bt = Bezier::BezierBernstein(t, n, i);
            v0.x += Bt * vectors[i].x;
            v0.y += Bt * vectors[i].y;
        }
        sf::Vector2f v1;
        while (t < 1.0)
        {
            t += h;
            v1 = sf::Vector2f(0.f, 0.f);
            for (int i = 0; i <= n; i++)
            {
                double Bt = Bezier::BezierBernstein(t, n, i);
                v1.x += Bt * vectors[i].x;
                v1.y += Bt * vectors[i].y;
            }
            this->lines.push_back(new eke::Line(v0, v1, *this->color));
            // for (size_t i = 0; i < this->lines.size(); i++)
            // {
            //     this->lines[i]->SetColor(*this->color, *this->color);
            // }
            v0 = v1;
        }
    }

    Bezier2Arc::~Bezier2Arc()
    {
        delete this->curve;
        for (size_t i = 0; i < this->lines.size(); i++)
        {
            delete this->lines[i];
        }
        this->lines.clear();
    }

    void Bezier2Arc::PollEvents()
    {
        if (eke::Globals::Event->type == sf::Event::MouseButtonPressed && eke::Globals::Event->mouseButton.button == sf::Mouse::Left)
        {
            this->positions.push_back(sf::Vector2f(eke::Globals::MousePosition));
        }
    }

    void Bezier2Arc::Update()
    {
        if (this->vectorsize < this->positions.size())
        {
            std::cout << this->positions[this->positions.size() - 1].x << " " << this->positions[this->positions.size() - 1].y << " " << this->positions.size() << std::endl;

            // Set stored size
            this->vectorsize = this->positions.size();

            // Clearing lines
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                delete this->lines[i];
            }
            this->lines.clear();

            // Generating Bezier again with modified vectors
            double t = 0.0;
            double h = 1.0 / 100;
            int n = this->positions.size() - 1;
            sf::Vector2f v0 = sf::Vector2f(0.f, 0.f);
            for (int i = 0; i <= n; i++)
            {
                double Bt = Bezier::BezierBernstein(t, n, i);
                v0.x += Bt * this->positions[i].x;
                v0.y += Bt * this->positions[i].y;
            }
            sf::Vector2f v1;
            while (t < 1.0)
            {
                t += h;
                v1 = sf::Vector2f(0.f, 0.f);
                for (int i = 0; i <= n; i++)
                {
                    double Bt = Bezier::BezierBernstein(t, n, i);
                    v1.x += Bt * this->positions[i].x;
                    v1.y += Bt * this->positions[i].y;
                }
                this->lines.push_back(new eke::Line(v0, v1, *this->color));
                // for (size_t i = 0; i < this->lines.size(); i++)
                // {
                //     this->lines[i]->SetColor(*this->color, *this->color);
                // }
                v0 = v1;
            }
        }
    }

    void Bezier2Arc::Update(const std::vector<sf::Vector2f> &vectors)
    {

        if (this->vectorsize < vectors.size())
        {
            std::cout << vectors[vectors.size() - 1].x << " " << vectors[vectors.size() - 1].y << " " << vectors.size() << std::endl;

            // Set stored size
            this->vectorsize = vectors.size();

            // Clearing lines
            for (size_t i = 0; i < this->lines.size(); i++)
            {
                delete this->lines[i];
            }
            this->lines.clear();

            // Generating Bezier again with modified vectors
            double t = 0.0;
            double h = 1.0 / 100;
            int n = vectors.size() - 1;
            sf::Vector2f v0 = sf::Vector2f(0.f, 0.f);
            for (int i = 0; i <= n; i++)
            {
                double Bt = Bezier::BezierBernstein(t, n, i);
                v0.x += Bt * vectors[i].x;
                v0.y += Bt * vectors[i].y;
            }
            sf::Vector2f v1;
            while (t < 1.0)
            {
                t += h;
                v1 = sf::Vector2f(0.f, 0.f);
                for (int i = 0; i <= n; i++)
                {
                    double Bt = Bezier::BezierBernstein(t, n, i);
                    v1.x += Bt * vectors[i].x;
                    v1.y += Bt * vectors[i].y;
                }
                this->lines.push_back(new eke::Line(v0, v1, *this->color));
                v0 = v1;
            }
        }
    }

    void Bezier2Arc::Draw()
    {
        if (this->curve != nullptr)
        {
            this->curve->Draw();
        }
        else
        {
            if (this->lines.size() > 0)
            {
                for (size_t i = 0; i < this->lines.size(); i++)
                {
                    this->lines[i]->Draw();
                }
            }
        }
    }
}