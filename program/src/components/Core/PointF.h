#ifndef POINTF_HPP
#define POINTF_HPP 1

namespace eke
{
    class PointF
    {
    public:
        float x, y;

        PointF();
        PointF(const float &x, const float &y);
        PointF(const PointF &other);
        ~PointF();
    };
}

#endif