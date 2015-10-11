using System;
using System.Diagnostics;

namespace euler
{
    class Problem139
    {
        public static void Main(string[] args)
        {
            new Problem139().Pell();
        }

        public void Pell()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;
            long limit = 100000000;

            long x = 1;
            long y = 1;

            while (x + y < limit)
            {
                long xnew = 3 * x + 4 * y;
                long ynew = 2 * x + 3 * y;

                x = xnew;
                y = ynew;

                result += limit / (x + y);

                //Console.WriteLine("x = {0}, y = {1}", xnew, ynew);                
            }

            clock.Stop();
            Console.WriteLine("Number of squares less than 100000000 : {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void BruteForce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long limit = 100000000;

            long result = 0;
            long mlimit = (long)Math.Sqrt(limit / 2);

            for (long m = 2; m < mlimit; m++)
            {
                for (long n = 1; n < m; n++)
                {
                    if (((n + m) % 2) == 1 && GCD(n, m) == 1)
                    {
                        long a = 2 * m * n;
                        long b = m * m - n * n;
                        long c = m * m + n * n;
                        long p = a + b + c;
                        if (c % (b - a) == 0)
                            result += limit / p;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("Number of squares less than 100000000 : {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
