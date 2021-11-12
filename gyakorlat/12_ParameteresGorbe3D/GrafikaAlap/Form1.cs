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
        Vector4 v = new Vector4(1.3, 1.0, 0.1);
        Matrix4 proj;
        Matrix4 rotX;
        double alpha = 0.4;
        double r = 50.0;
        double m = 1.0;
        Pen pen = new Pen(Color.Blue, 2f);
        Vector2 center;

        public Form1()
        {
            InitializeComponent();
            rotX = Matrix4.RotX(alpha);
            proj = Matrix4.Parallel(v);
            center = new Vector2(canvas.Width / 2, canvas.Height / 2);
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            g.DrawParametricCurve3D(pen,
                t => r * Math.Cos(t),
                t => r * Math.Sin(t),
                t => (m * t) / (2 * Math.PI),
                proj,
                rotX,
                -4 * Math.PI, 4 * Math.PI,
                center);
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
