#ifndef MATRIX4_HPP
#define MATRIX4_HPP 1

#include <stddef.h>

namespace eke
{
    class Matrix4
    {
    public:
        double m[4][4];

        Matrix4();
        Matrix4(const Matrix4 &other);
        ~Matrix4();
        void LoadIdentity();

    public:
        void operator+(const Matrix4 &other);
        void operator*(const Matrix4 &other);
    };
}

#endif