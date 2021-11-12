using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GrafikaDLL;

/*
 * 1. Érintők végpontjainak mozgatása
 * 2. Görbe végpontjainak mozgatása az adott pontbeli érintő meredekségének megőrzésével
 * 3. Az s változó scrollbar-ral való módosítása
 */

namespace GrafikaAlap
{
    public partial class Form1 : Form
    {
        Graphics g;
        Vector2 p0, p1, q0, q1;

        public Form1()
        {
            InitializeComponent();
            p0 = new Vector2(200, 300);
            q0 = new Vector2(400, 50);
            p1 = new Vector2(500, 250);
            q1 = new Vector2(600, 450);
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            double s = 2.0;
            g.DrawHermiteArc(new Pen(Color.Blue, 2f), p0, p1, s * (q0 - p0), s * (q1 - p1));

            g.DrawLine(Pens.Black, p0, q0);
            g.DrawLine(Pens.Black, p1, q1);
            g.DrawPoint(Pens.Black, Brushes.White, p0, 5);
            g.DrawPoint(Pens.Black, Brushes.White, p1, 5);
        }
        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
    }
}
