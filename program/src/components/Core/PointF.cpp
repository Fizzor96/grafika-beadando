#include "PointF.h"

namespace eke
{
    PointF::PointF()
    {
    }

    PointF::PointF(const float &x, const float &y)
    {
        this->x = x;
        this->y = y;
    }

    PointF::PointF(const PointF &other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    PointF::~PointF()
    {
    }
}
