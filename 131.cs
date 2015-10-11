using System;
using System.Diagnostics;

namespace euler
{
    class Problem131
    {
        public static void Main(string[] args)
        {
            new Problem131().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;
            for (int i = 1; i < 577; i++)
            {
                if (IsPrime((i + 1) * (i + 1) * (i + 1) - i * i * i))
                    result++;
            }

            clock.Stop();
            Console.WriteLine("Number of primes with this property: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool IsPrime(int n)
        {
            if (n < 2)
                return false;
            if (n < 4)
                return true;
            if (n % 2 == 0)
                return false;
            if (n < 9)
                return true;
            if (n % 3 == 0)
                return false;
            if (n < 25)
                return true;

            int s = (int)Math.Sqrt(n);
            for (int i = 5; i <= s; i += 6)
            {
                if (n % i == 0)
                    return false;
                if (n % (i + 2) == 0)
                    return false;
            }

            return true;
        }
    }
}
