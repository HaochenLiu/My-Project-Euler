using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class Problem113
    {
        public static void Main(string[] args)
        {
            new Problem113().Combinatorics();
        }

        public void Combinatorics()
        {
            Stopwatch clock = Stopwatch.StartNew();

            BigInteger result = Choose(100 + 10, 10) + Choose(100 + 9, 9) - 10 * 100 - 2;

            clock.Stop();
            Console.WriteLine("There are {0} non-bouncy numbers below 10^100 ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public static BigInteger Choose(int n, int k)
        {
            k = Math.Min(k, n - k);

            BigInteger res = 1;
            for (int i = 1; i <= k; i++)
            {
                res *= n - k + i;
                res /= i;
            }

            return res;
        }
    }
}
