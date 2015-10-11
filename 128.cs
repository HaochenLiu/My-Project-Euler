using System;
using System.Diagnostics;

namespace euler
{
    class Problem128
    {
        public static void Main(string[] args)
        {
            new Problem128().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int count = 1;
            int limit = 2000;
            long n = 0;
            long number = 0;

            while (count < limit)
            {
                n++;
                if (IsPrime(6 * n - 1) && IsPrime(6 * n + 1) && IsPrime(12 * n + 5))
                {
                    count++;
                    number = (3 * n * n - 3 * n + 2);
                    if (count >= limit) break;

                }
                if (IsPrime(6 * n + 5) && IsPrime(6 * n - 1) && IsPrime(12 * n - 7) && n != 1)
                {
                    count++;
                    number = (3 * n * n + 3 * n + 1);
                }
            }

            clock.Stop();
            Console.WriteLine("The {0}th number is {1}", limit, number);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public static bool IsPrime(long n)
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
