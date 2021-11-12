using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public class HermiteArc
    {
        public Vector2 p0, p1, q0, q1;
        public double weight;

        public HermiteArc(Vector2 p0, Vector2 p1, 
            Vector2 q0, Vector2 q1, double weight = 1.0)
        {
            this.p0 = new Vector2(p0.x, p0.y);
            this.p1 = new Vector2(p1.x, p1.y);
            this.q0 = new Vector2(q0.x, q0.y);
            this.q1 = new Vector2(q1.x, q1.y);
            this.weight = weight;
        }
    }
}
