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
        PointF p1 = new PointF(100, 150);
        PointF p2 = new PointF(500, 250);
        int gotcha = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.DrawLineDDA(Color.Red, Color.Green, p1, p2);
            g.DrawPolygon(new Color[] { Color.Red, Color.Yellow, Color.Blue, Color.Salmon },
                          new PointF[] { 
                            new PointF(100, 120),
                            new PointF(300, 50),
                            new PointF(540, 250),
                            new PointF(150, 300),
                          });
        }
        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (e.CloseEnough(p1)) gotcha = 1;
                    else if (e.CloseEnough(p2)) gotcha = 2;
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
                    if (gotcha != 0)
                    {
                        if (gotcha == 1) p1 = e.Location;
                        else p2 = e.Location;

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
                    gotcha = 0;
                    break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
    }
}
