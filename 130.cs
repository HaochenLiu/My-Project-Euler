using System;
using System.Diagnostics;

namespace euler
{
    class Problem130
    {
        public static void Main(string[] args)
        {
            new Problem130().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 25;
            int found = 0;

            int n = 1;
            int result = 0;

            while (found < limit)
            {
                n++;

                if (IsPrime(n)) continue;

                int a = A(n);

                if (a != 0 && ((n - 1) % a == 0))
                {
                    result += n;
                    found++;
                }

            }

            clock.Stop();
            Console.WriteLine("The sum of the first {0} of these composite numbers is {1}", limit, result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int A(int n)
        {
            if (GCD(n, 10) != 1) return 0;

            int x = 1;
            int k = 1;

            while (x != 0)
            {
                x = (x * 10 + 1) % n;
                k++;
            }

            return k;
        }

        private int GCD(int a, int b)
        {
            return b == 0 ? a : GCD(b, a % b);
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
