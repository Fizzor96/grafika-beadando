using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public static class BezierP
    {
        public static double B0(double t, double p)
        {
            return (1 - t) * (1 - t) * (1 + (2 - p) * t);
        }
        public static double B1(double t, double p)
        {
            return p * t * (1 - t) * (1 - t);
        }
        public static double B2(double t, double p)
        {
            return p * t * t * (1 - t);
        }
        public static double B3(double t, double p)
        {
            return t * t * (3 - p + (p - 2) * t);
        }
    }
}
