#include "Vector4.h"

namespace eke
{
    Vector4::Vector4()
    {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
        this->w = 1.0;
    }

    Vector4::Vector4(const double &x, const double &y, const double &z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = 1.0;
    }

    Vector4::Vector4(const double &x, const double &y, const double &z, const double &w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vector4::Vector4(const Vector4 &vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = vec.w;
    }

    Vector4::~Vector4()
    {
    }

    double Vector4::Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    void Vector4::Normalize()
    {
        double len = this->Length();
        x /= len;
        y /= len;
        z /= len;
    }

    void Vector4::operator+(const Vector4 &v)
    {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
        this->w = 1.0;
    }

    void Vector4::operator+(const sf::Vector2f &v)
    {
        this->x += v.x;
        this->y += v.y;
        this->z = this->z;
        this->w = 1.0;
    }

    void Vector4::operator-()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        this->w = 1.0;
    }

    void Vector4::operator-(const Vector4 &v)
    {
        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;
        this->w = 1.0;
    }

    void Vector4::operator^(const Vector4 &v)
    {
        this->x = this->y * v.z - this->z * v.y;
        this->y = this->z * v.x - this->x * v.z;
        this->z = this->x * v.y - this->y * v.x;
    }

    void Vector4::operator*(const Vector4 &v)
    {
        this->x = this->x * v.x;
        this->y = this->y * v.y;
        this->z = this->z * v.z;
    }
}