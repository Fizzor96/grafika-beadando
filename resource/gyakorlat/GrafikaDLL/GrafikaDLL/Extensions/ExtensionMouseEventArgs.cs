using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GrafikaDLL
{
    public static class ExtensionMouseEventArgs
    {
        public static float eps = 5;

        public static bool CloseEnough(this MouseEventArgs e, PointF p)
        {
            return Math.Abs(p.X - e.X) <= eps && Math.Abs(p.Y - e.Y) <= eps;
        }
        public static bool CloseEnough(this MouseEventArgs e, Vector2 v)
        {
            return Math.Abs(v.x - e.X) <= eps && Math.Abs(v.y - e.Y) <= eps;
        }

        public static bool Catch(this MouseEventArgs e, Rectangle rect, out int dx, out int dy)
        {
            dx = 0; dy = 0;
            if (rect.Left <= e.X && e.X < rect.Right &&
                rect.Top <= e.Y && e.Y < rect.Bottom)
            {
                dx = e.X - rect.Left;
                dy = e.Y - rect.Top;
                return true;
            }
            return false;
        }
    }
}
