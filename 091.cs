using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading;
using System.IO;
using System.Text.RegularExpressions;

namespace PE
{
    class Program
    {
        private static int gcd(int a, int b)
        {
            if (a < b) return gcd(b, a);
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        static void Main(string[] args)
        {
            int size = 50;
            int result = size * size * 3;
            for (int x = 1; x <= size; x++)
            {
                for (int y = 1; y <= size; y++)
                {
                    int fact = gcd(x, y);
                    result += Math.Min(y * fact / x, (size - x) * fact / y) * 2;
                }
            }
            Console.Write(result);
            Console.WriteLine();
        }
    }
}
