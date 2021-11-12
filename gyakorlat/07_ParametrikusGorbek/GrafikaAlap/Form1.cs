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

namespace GrafikaAlap
{
    public partial class Form1 : Form
    {
        Graphics g;
        double r = 100;
        double scale = 80;
        Vector2 o;
        double T = 0.00001;

        public Form1()
        {
            InitializeComponent();
            o = new Vector2(canvas.Width / 2, canvas.Height / 2);
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            //g.DrawLine(Pens.Black, 0, (float)o.y, canvas.Width, (float)o.y);
            //g.DrawLine(Pens.Black, (float)o.x, 0, (float)o.x, canvas.Height);

            //o középpontú r sugarú kör
            //g.DrawParametricCurve2D(Pens.Red,
            //    t => r * Math.Cos(t) + o.x,
            //    t => r * Math.Sin(t) + o.y,
            //    0, 2 * Math.PI);

            //g.DrawParametricCurve2D(new Pen(Color.Blue, 2f),
            //    t => scale * t + o.x,
            //    t => scale * -Math.Sin(t) + o.y,
            //    -2 * Math.PI, 2 * Math.PI);

            //Butterfly curve
            g.DrawParametricCurve2D(new Pen(Color.Blue, 1f),
                t => scale * Math.Sin(t) * (Math.Exp(Math.Cos(t)) - 2 * Math.Cos(4 * t) - Math.Pow(Math.Sin(t / 12.0), 5)) + o.x,
                t => scale * -Math.Cos(t) * (Math.Exp(Math.Cos(t)) - 2 * Math.Cos(4 * t) - Math.Pow(Math.Sin(t / 12.0), 5)) + canvas.Height * 3.0 / 5.0,
                0, T);
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

        private void timer_Tick(object sender, EventArgs e)
        {
            T += 0.01;
            canvas.Invalidate();
        }
    }
}
