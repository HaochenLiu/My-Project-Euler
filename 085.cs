using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PE
{
    class Program
    {
        private static int rectangles(int x, int y)
        {
            int rects = 0;
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    rects += (x - i) * (y - j);
                }
            }
            return rects;
        }

        static void Main(string[] args)
        {
            int closestarearects = 0;
            int closestarea = 0;
            int target = 2000000;

            for (int x = 1; x < 2000; x++)
            {
                for (int y = x; y < 2000; y++)
                {
                    int rects = rectangles(x, y);
                    if (Math.Abs(closestarearects - target)
                       > Math.Abs(rects - target))
                    {
                        closestarea = x * y;
                        closestarearects = rects;
                    }
                    if (rects > target) break;
                }
            }
            Console.Write(closestarea);
            Console.WriteLine();
        }
    }
}
