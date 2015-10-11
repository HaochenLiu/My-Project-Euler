using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class Problem267
    {
        public static void Main(string[] args)
        {
            new Problem267().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            double f = 0.5;
            double alpha = 1e-4;
            double fold = 0;

            while (Math.Abs(f - fold) > 1e-4)
            {
                double fdev = (L(f + 1e-6) - L(f)) / 1e-6;
                fold = f;
                f -= alpha * fdev;
            }

            BigInteger totalComb = BigInteger.Pow(2, 1000);
            BigInteger winningComb = 0;

            for (int h = (int)Math.Ceiling(L(f)); h <= 1000; h++)
            {
                winningComb += Choose(1000, h);
            }

            clock.Stop();
            Console.WriteLine("The chance of winning is maximized at {0}", f);
            Console.WriteLine("The chance of winning is {0}", (double)winningComb / (double)totalComb);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private double L(double f)
        {
            return (9 * Math.Log(10) - 1000 * Math.Log(1 - f)) / (Math.Log(1 + 2 * f) - Math.Log(1 - f));
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
