using System;
using System.Diagnostics;

namespace euler
{
    class Problem138
    {
        public static void Main(string[] args)
        {
            new Problem138().Pell();
        }

        public void Pell()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;

            long x = 0;
            long y = -1;

            for (int i = 0; i < 12; i++)
            {
                long xnew = -9 * x + -4 * y + 4;
                long ynew = -20 * x + -9 * y + 8;

                x = xnew;
                y = ynew;

                //Console.WriteLine("x = {0}, y = {1}", xnew, ynew);
                result += Math.Abs(y);
            }

            clock.Stop();
            Console.WriteLine("Sum of first 12 L : {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void FibSolution()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;

            for (int i = 0; i < 12; i++)
            {
                result += Fibonacci((i + 1) * 6 + 3) / 2;
            }

            clock.Stop();
            Console.WriteLine("Sum of first 12 L : {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public long Fibonacci(long k)
        {
            double sqrt5 = Math.Sqrt(5);
            return (long)((Math.Pow((1 + sqrt5) / 2, k) - Math.Pow((1 - sqrt5) / 2, k)) / sqrt5);
        }
    }
}
