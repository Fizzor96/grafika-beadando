#include "Matrix4.h"

namespace eke
{
    Matrix4::Matrix4()
    {
    }

    Matrix4::Matrix4(const Matrix4 &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                this->m[i][j] = other.m[i][j];
            }
        }
    }

    Matrix4::~Matrix4()
    {
    }

    void Matrix4::LoadIdentity()
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                this->m[i][j] = 0.0;
            }
        }
        this->m[0][0] = 1.0;
        this->m[1][1] = 1.0;
        this->m[2][2] = 1.0;
        this->m[3][3] = 1.0;
    }

    void Matrix4::operator+(const Matrix4 &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                this->m[i][j] = this->m[i][j] + other.m[i][j];
            }
        }
    }

    void Matrix4::operator*(const Matrix4 &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                double sum = 0.0;
                for (size_t k = 0; k < 4; k++)
                {
                    sum += this->m[i][k] * other.m[k][j];
                }
                this->m[i][j] = sum;
            }
        }
    }

}