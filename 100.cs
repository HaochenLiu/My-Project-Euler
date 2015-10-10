using System;
using System.Diagnostics;

namespace euler
{
    class Problem100
    {
        public static void Main(string[] args)
        {
            new Problem100().Diophantine();
        }

        public void Diophantine()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long b = 15;
            long n = 20;
            long target = 1000000000000;

            while (n < target)
            {
                long btemp = 3 * b + 2 * n - 2;
                long ntemp = 4 * b + 3 * n - 3;

                b = btemp;
                n = ntemp;
            }

            clock.Stop();
            Console.WriteLine("There are {0} blues", b);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
