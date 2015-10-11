using System;
using System.Diagnostics;
using System.Linq;

namespace euler
{
    class Problem135
    {
        public static void Main(string[] args)
        {
            new Problem135().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int n = 1000000;
            int[] solutions = new int[n + 1];

            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; u * v <= n; v++)
                {
                    if ((u + v) % 4 == 0 &&
                        3 * v > u &&
                        ((3 * v - u) % 4) == 0)
                        solutions[u * v]++;
                }
            }

            int result = solutions.Where(x => x == 10).Count();

            clock.Stop();
            Console.WriteLine("number of values with exactly 10 solutions: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
