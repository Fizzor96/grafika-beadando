using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public class BezierPArc
    {
        public Vector2 p0, p1, p2, p3;
        public double p;

        public BezierPArc(double p)
        {
            this.p = p;
            this.p0 = new Vector2(0.0, 0.0);
            this.p1 = new Vector2(0.0, 0.0);
            this.p2 = new Vector2(0.0, 0.0);
            this.p3 = new Vector2(0.0, 0.0);
        }
        public BezierPArc(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, 
            double p)
        {
            this.p = p;
            this.p0 = new Vector2(p0.x, p0.y);
            this.p1 = new Vector2(p1.x, p1.y);
            this.p2 = new Vector2(p2.x, p2.y);
            this.p3 = new Vector2(p3.x, p3.y);
        }
    }
}
