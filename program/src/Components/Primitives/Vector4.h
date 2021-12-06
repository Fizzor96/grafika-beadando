#ifndef VECTOR4_HPP
#define VECTOR4_HPP 1

#include <SFML/Graphics.hpp>
#include <math.h>

namespace eke
{
    class Vector4
    {
    public:
        double x, y, z, w;
        Vector4();
        Vector4(const double &x, const double &y, const double &z);
        Vector4(const double &x, const double &y, const double &z, const double &w);
        Vector4(const Vector4 &vec);
        double Length() const;
        void Normalize();
        ~Vector4();

    public:
        void operator+(const Vector4 &v);
        void operator+(const sf::Vector2f &v);
        void operator-();
        void operator-(const Vector4 &v);
        void operator^(const Vector4 &v);
        void operator*(const Vector4 &v);
    };
}

#endif