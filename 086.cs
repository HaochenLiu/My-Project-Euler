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
            int l = 2;
            int count = 0;
            int target = 1000000;

            while (count < target)
            {
                l++;
                for (int wh = 3; wh <= 2 * l; wh++)
                {
                    double sqrt = Math.Sqrt(wh * wh + l * l);
                    if (sqrt == (int)(sqrt))
                    {
                        count += (wh <= l) ? wh / 2 : 1 + (l - (wh + 1) / 2);
                    }
                }
            }
            Console.Write(l);
            Console.WriteLine();
        }
    }
}
