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
        Random rnd = new Random();

        PointF P = new PointF(50, 50);
        float size = 200;
        Brush brushSquare = new SolidBrush(Color.Salmon);

        bool gotcha = false;
        float dx, dy;

        float speedX = 1, speedY = 1;
        int counter = 0;

        public Form1()
        {
            InitializeComponent();
            timer.Start();
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;

            g.FillRectangle(brushSquare, P.X, P.Y, size, size);
        }
        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (P.X <= e.X && e.X < P.X + size &&
                        P.Y <= e.Y && e.Y < P.Y + size)
                    {
                        dx = e.X - P.X;
                        dy = e.Y - P.Y;
                        gotcha = true;

                        counter++;
                        if (counter == 5)
                        {
                            MessageBox.Show("2-est kaptál bevezetés a valamiből...");
                            Application.Exit();
                        }
                    }
                    break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (gotcha)
                    {
                        P.X = e.X - dx;
                        P.Y = e.Y - dy;

                        if (P.X < 0) P.X = 0;
                        else if (P.X > canvas.Width - size) P.X = canvas.Width - size;
                        if (P.Y < 0) P.Y = 0;
                        else if (P.Y > canvas.Height - size) P.Y = canvas.Height - size;

                        canvas.Invalidate();
                    }
                    break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    gotcha = false;
                    size -= 10;
                    speedX = rnd.NextDouble() > 0.5 ? -speedX : speedX;
                    speedY = rnd.NextDouble() > 0.5 ? -speedY : speedY;
                    if (speedX > 0) speedX += 2;
                    else speedX -= 2;
                    if (speedY > 0) speedY += 2;
                    else speedY -= 2;
                    brushSquare = new SolidBrush(Color.FromArgb(
                        rnd.Next(256), rnd.Next(256), rnd.Next(256)));
                    break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (!gotcha)
            {
                P.X += speedX;
                P.Y += speedY;

                if (P.X < 0 || P.X > canvas.Width - size) speedX *= -1;
                if (P.Y < 0 || P.Y > canvas.Height - size) speedY *= -1;

                canvas.Invalidate();
            }
        }
    }
}
