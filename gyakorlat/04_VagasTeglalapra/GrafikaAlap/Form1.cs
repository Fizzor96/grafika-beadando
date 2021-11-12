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
        Random rnd = new Random();
        List<Rectangle> windows;
        Line[] lines = new Line[100];
        //Mindegyik vonalnak generáljanak saját állandó színt
        PointF p0, p1;

        public Form1()
        {
            InitializeComponent();

            for (int i = 0; i < lines.Length; i++)
                lines[i] = new Line(rnd.Next(canvas.Width), rnd.Next(canvas.Height),
                                    rnd.Next(canvas.Width), rnd.Next(canvas.Height));

            windows = new List<Rectangle>{ 
                new Rectangle(20, 30, 120, 230),
                new Rectangle(170, 150, 210, 80),
                new Rectangle(410, 10, 50, 300)
            };
            p0 = new PointF(20, 30);
            p1 = new PointF(canvas.Width - 50, canvas.Height - 10);
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            for (int i = 0; i < windows.Count; i++)
            {
                g.DrawRectangle(Pens.Black, windows[i]);
                for (int j = 0; j < lines.Length; j++)
                    g.Clip(Pens.Blue, windows[i], lines[j]);
            }            
        }
        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: 
                    //Megnézem, hogy üres területre kattintottam-e (nem kattintottam bele egy ablakba sem)
                    //Eltárolom, hogy melyi ablakot fogtam meg
                    //Eltárolom, hogy jobb-alsó srkot azonnal meg is fogtam
                    //Rajzolok
                    break;
                default: break;
            }
        }
        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: 
                    //Ha valamelyik meg van fogva, akkor
                    //ha a jobb alsó sarok van megfogva, akkor a szélesség-magasság
                    //  értékeket módosítom
                    //Rajzolok
                    break;
                default: break;
            }
        }
        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left: break;
                case MouseButtons.Middle: break;
                case MouseButtons.Right: 
                    //Elengedem a téglalapot
                    break;
                default: break;
            }
        }
    }
}
