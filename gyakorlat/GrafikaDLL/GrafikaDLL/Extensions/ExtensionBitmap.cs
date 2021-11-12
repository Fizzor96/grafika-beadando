using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public static class ExtensionBitmap
    {
        public static void SetLine(this Bitmap bmp, int x1, int y1, 
            int x2, int y2, Color color)
        {
            float dx = x2 - x1;
            float dy = y2 - y1;
            float length = Math.Abs(dx) > Math.Abs(dy) ? Math.Abs(dx) : Math.Abs(dy);
            float incX = dx / length;
            float incY = dy / length;
            float x = x1;
            float y = y1;
            bmp.SetPixel((int)x, (int)y, color);
            for (int i = 0; i < length; i++)
            {
                x += incX;
                y += incY;
                bmp.SetPixel((int)x, (int)y, color);
            }
        }

        public static void FillEdgeFlag(this Bitmap bmp,
            Color background, Color fillColor)
        {
            bool inside;
            for (int y = 0; y < bmp.Height; y++)
            {
                inside = false;
                for (int x = 0; x < bmp.Width; x++)
                {
                    //Kezelni kell azt az esetet, amikor egymás mellett (vízszintesen)
                    //páros számú határpixel van.
                    if (!bmp.GetPixel(x, y).IsTheSameAs(background))
                    {
                        inside = !inside;
                        continue;
                    }
                    if (inside)
                        bmp.SetPixel(x, y, fillColor);
                }
            }
        }
               
        public static void FillRec4(this Bitmap bmp,
            Color background, Color fillcolor, Point p)
        {
            if (bmp.GetPixel(p.X, p.Y).IsTheSameAs(background))
            {
                bmp.SetPixel(p.X, p.Y, fillcolor);
                bmp.FillRec4(background, fillcolor, new Point(p.X + 1, p.Y));
                bmp.FillRec4(background, fillcolor, new Point(p.X - 1, p.Y));
                bmp.FillRec4(background, fillcolor, new Point(p.X, p.Y + 1));
                bmp.FillRec4(background, fillcolor, new Point(p.X, p.Y - 1));
            }
        }
         public static void FillRec8(this Bitmap bmp,
            Color background, Color fillcolor, Point p)
        {
            throw new NotImplementedException();
        }
         public static void FillStack4(this Bitmap bmp,
             Color background, Color fillcolor, Point p)
         {
             int[] dx = new int[] { 0, 1, 0, -1 };
             int[] dy = new int[] { 1, 0, -1, 0 };
             Stack<Point> stack = new Stack<Point>();
             stack.Push(p);
             Point p0, p1;
             while(stack.Count > 0)
             {
                 p0 = stack.Pop();
                 bmp.SetPixel(p0.X, p0.Y, fillcolor);
                 for (int i = 0; i < 4; i++)
                 {
                     p1 = new Point(p0.X + dx[i], p0.Y + dy[i]);
                     if (bmp.GetPixel(p1.X, p1.Y).IsTheSameAs(background))
                         stack.Push(p1);
                 }
             }
         }
         public static void FillStack8(this Bitmap bmp,
              Color background, Color fillcolor, Point p)
         {
             throw new NotImplementedException();
         }
    }
}
