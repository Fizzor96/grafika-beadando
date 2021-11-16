﻿using System;
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
        List<Vector2> V = new List<Vector2>();
        int grabbed = -1;

        public Form1()
        {
            InitializeComponent();
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            for (int i = 0; i < V.Count - 1; i++)
                g.DrawLine(Pens.Gray, V[i], V[i + 1]);
            for (int i = 0; i < V.Count; i++)
                g.DrawPoint(Pens.Gray, Brushes.White, V[i], 5);
            g.DrawBezier(new Pen(Color.Blue, 2f), V);
        }
        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    for (int i = 0; i < V.Count; i++)
                    {
                        if (e.CloseEnough(V[i]))
                            grabbed = i;
                    }
                    if (grabbed == -1)
                    {
                        V.Add(new Vector2(e.X, e.Y));
                        grabbed = V.Count - 1;
                        canvas.Invalidate();
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
                    if (grabbed != -1)
                    {
                        V[grabbed] = new Vector2(e.X, e.Y);
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
                    grabbed = -1;
                    break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: break;
                default: break;
            }
        }
    }
}