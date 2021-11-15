using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GrafikaAlap
{
    public partial class Form1 : Form
    {
        Graphics g;
        PointF center;
        Pen penCoordSys = new Pen(Color.Black, 3f);

        public Form1()
        {
            InitializeComponent();

            center = new PointF(canvas.Width / 2f, canvas.Height / 2f);
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;

            g.DrawLine(penCoordSys, 0, center.Y, canvas.Width, center.Y);
            g.DrawLine(penCoordSys, center.X, 0, center.X, canvas.Height);

            g.FillRectangle(Brushes.Yellow, 100, 100, 150, 350);
            g.DrawRectangle(Pens.Black, 100, 100, 150, 350);
            g.FillEllipse(new SolidBrush(Color.Red), 100, 100, 150, 350);
            g.DrawEllipse(new Pen(Color.Green, 5f), 100, 100, 150, 350);

            PointF P = new PointF(450, 100);
            float r = 50;
            g.DrawEllipse(Pens.Red, P.X - r, P.Y - r, 2 * r, 2 * r);
            g.DrawRectangle(Pens.Black, P.X, P.Y, 0.5f, 0.5f);

            P = new PointF(400, 170);
            for (int i = 0; i < 256; i++)
                for (int j = 0; j < 256; j++)
                    g.DrawRectangle(new Pen(Color.FromArgb((i + j) % 256, i, j)), P.X + i, P.Y + j, 0.5f, 0.5f);
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
