using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafikaDLL
{
    public struct KeyPair
    {
        public KeyPair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int x, y;
    }
}
