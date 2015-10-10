using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class Problem097
    {

        public static void Main(string[] args)
        {
            new Problem097().BruteForce();
        }

        public void BruteForce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long mod = 10000000000;
            BigInteger result = 28433 * BigInteger.ModPow(2, 7830457, mod) + 1;
            result %= mod;

            clock.Stop();
            Console.WriteLine("The last 10 digits are {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }


    }
}
