using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public static class BezierBernstein
    {
        static Binomial bin = new Binomial();

        public static double B(double t, int n, int i)
        {
            return bin.Binom(n, i) * Math.Pow(1 - t, n - i) * Math.Pow(t, i);
        }        
    }
}
