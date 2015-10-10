using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace euler
{
    class Problem094
    {
        public static void Main(string[] args)
        {
            new Problem094().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long x = 2;
            long y = 1;
            long limit = 1000000000;
            long result = 0;

            while (true)
            {
                // b = a+1
                long aTimes3 = 2 * x - 1;
                long areaTimes3 = y * (x - 2);
                if (aTimes3 > limit) break;

                if (aTimes3 > 0 &&
                 areaTimes3 > 0 &&
                 aTimes3 % 3 == 0 &&
                 areaTimes3 % 3 == 0)
                {
                    long a = aTimes3 / 3;
                    long area = areaTimes3 / 3;

                    result += 3 * a + 1;
                    //Console.WriteLine("({0}, {0}, {1}), perimeter = {2}, area = {3}", a, a + 1, 3 * a + 1, area);
                }

                //b = a-1
                aTimes3 = 2 * x + 1;
                areaTimes3 = y * (x + 2);

                if (aTimes3 > 0 &&
                    areaTimes3 > 0 &&
                    aTimes3 % 3 == 0 &&
                    areaTimes3 % 3 == 0)
                {
                    long a = aTimes3 / 3;
                    long area = areaTimes3 / 3;

                    result += 3 * a - 1;
                    //Console.WriteLine("({0}, {0}, {1}), perimeter = {2}, area = {3}", a, a + 1, 3 * a + 1, area);
                }

                long nextx = 2 * x + y * 3;
                long nexty = y * 2 + x;

                x = nextx;
                y = nexty;
            }

            clock.Stop();
            Console.Write("The sum of perimiters is {0}", result);
            Console.WriteLine();
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
