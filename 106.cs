using System;
using System.Diagnostics;

namespace euler
{
    class Problem106
    {

        public static void Main(string[] args)
        {
            new Problem106().Combinatorics();
        }

        public void Combinatorics()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;
            int n = 12;

            for (int i = 2; i <= n / 2; i++)
            {
                result += Choose(n, i) * Choose(n - i, i) / 2;
                result -= Choose(n, 2 * i) * CatalanNumber(i);
            }

            clock.Stop();
            Console.WriteLine("The number of subsets needed to check {0} ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int CatalanNumber(int n)
        {
            return Choose(2 * n, n) / (n + 1);
        }

        public static int Choose(int n, int k)
        {
            k = Math.Min(k, n - k);

            int res = 1;
            for (int i = 1; i <= k; i++)
            {
                res *= n - k + i;
                res /= i;
            }

            return res;
        }
    }
}
