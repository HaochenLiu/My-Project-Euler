using System;
using System.Diagnostics;

namespace euler
{
    class Problem137
    {
        public static void Main(string[] args)
        {
            new Problem137().BruteForce();
        }

        //Only work up to around 11th nugget
        public void BruteForce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long k = 1;
            int count = 0;
            int limit = 15;

            while (count < limit)
            {
                long discriminantSquared = (k + 1) * (k + 1) + 4 * k * k;
                long discriminant = (long)Math.Sqrt(discriminantSquared);

                if (discriminant * discriminant == discriminantSquared)
                {
                    Console.Write((count + 1) + ": " + discriminant + " ");
                    Console.Write((k + 1) * (k + 1) + 4 * k * k + " ");
                    Console.WriteLine(k);
                    count++;
                }
                k++;
            }

            clock.Stop();
            Console.WriteLine("The 15th nugget: {0}", k);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Solve()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;

            for (int k = 1; k < 16; k++)
            {
                result = Fibonacci(2 * k) * Fibonacci(2 * k + 1);
                Console.WriteLine(result);
            }

            clock.Stop();
            Console.WriteLine("The 15th nugget: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public long Fibonacci(long k)
        {
            double sqrt5 = Math.Sqrt(5);
            return (long)((Math.Pow((1 + sqrt5) / 2, k) - Math.Pow((1 - sqrt5) / 2, k)) / sqrt5);
        }
    }
}
