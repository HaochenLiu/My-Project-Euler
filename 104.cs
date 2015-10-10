using System;
using System.Diagnostics;
using System.Numerics;


namespace euler
{
    class Problem104
    {
        public static void Main(string[] args)
        {
            new Problem104().BruteForce();
            new Problem104().BruteForce2();
        }

        public void BruteForce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            BigInteger fn2 = 1;
            BigInteger fn1 = 1;
            BigInteger fn;

            BigInteger tailcut = 1000000000;

            int n = 2;
            bool found = false;

            while (!found)
            {
                n++;

                fn = fn1 + fn2;
                long tail = (long)(fn % tailcut);
                if (IsPandigital(tail))
                {
                    int digits = (int)Math.Ceiling(BigInteger.Log10(fn));
                    if (digits > 9)
                    {
                        long head = (long)(fn / BigInteger.Pow(10, digits - 9));
                        if (IsPandigital(head))
                        {
                            found = true;
                        }
                    }
                }

                fn2 = fn1;
                fn1 = fn;
            }

            clock.Stop();
            Console.WriteLine("Fibonacci number {0} is the first solution ", n);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void BruteForce2()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long fn2 = 1;
            long fn1 = 1;
            long fn;

            long tailcut = 1000000000;

            int n = 2;
            bool found = false;

            while (!found)
            {
                n++;
                fn = (fn1 + fn2) % tailcut;
                fn2 = fn1;
                fn1 = fn;

                if (IsPandigital(fn))
                {
                    double t = (n * 0.20898764024997873 - 0.3494850021680094);
                    if (IsPandigital((long)Math.Pow(10, t - (long)t + 8)))
                    {
                        Console.WriteLine(t);
                        found = true;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("Fibonacci number {0} is the first solution ", n);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool IsPandigital(long n, bool includeZero = false)
        {
            int digits = 0;
            int count = 0;
            int tmp;

            if (n == 0)
            {
                return includeZero;
            }

            while (n > 0)
            {
                tmp = digits;
                digits |= 1 << (int)(n % 10);
                if (tmp == digits) //Check to see if the same digit is found multiple times
                    return false;

                count++;
                n /= 10;
            }

            int mask = (1 << count) - 1;
            if (!includeZero)
                mask <<= 1;

            return digits == mask;
        }
    }
}
