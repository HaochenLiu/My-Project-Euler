using System;
using System.Diagnostics;

namespace euler
{
    class Problem120
    {
        public static void Main(string[] args)
        {
            new Problem120().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int r = 0;
            for (int a = 3; a <= 1000; a++)
            {
                r += 2 * a * ((a - 1) / 2);
            }

            clock.Stop();
            Console.WriteLine("sum of r max = {0}", r);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
