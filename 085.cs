using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PE
{
    class Program
    {
        static void Main(string[] args)
        {
            int error = int.MaxValue;
            int closestarea = 0;
            int target = 2000000;

            int x = 2000;
            int y = 1;

            while (x >= y)
            {
                int rects = x * (x + 1) * y * (y + 1) / 4;

                if (error > Math.Abs(rects - target))
                {
                    closestarea = x * y;
                    error = Math.Abs(rects - target);
                }

                if (rects > target)
                    x--;
                else
                    y++;
            }
            Console.Write(closestarea);
            Console.WriteLine();
        }
    }
}
