/*
http://www.mathblog.dk/project-euler-80-digits-irrational-square-roots/
https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PE
{
    class Program
    {
        private static BigInteger Squareroot(int n, int digits)
        {
            BigInteger limit = BigInteger.Pow(10, digits + 1);
            BigInteger a = 5 * n;
            BigInteger b = 5;

            while (b < limit)
            {
                if (a >= b)
                {
                    a -= b;
                    b += 10;
                }
                else
                {
                    a *= 100;
                    b = (b / 10) * 100 + 5;
                }
            }

            return b / 100;
        }

        static void Main(string[] args)
        {
            int result = 0;
            int j = 1;

            for (int i = 1; i <= 100; i++)
            {
                if (j * j == i)
                {
                    j++;
                    continue;
                }
                string s = Squareroot(i, 100).ToString();
                for (int k = 0; k < s.Length; k++)
                {
                    result += (s[k] - '0');
                }
                Console.Write(result);
                Console.WriteLine();
            }
        }
    }
}
