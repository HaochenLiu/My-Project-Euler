using System;
using System.Diagnostics;

namespace euler
{
    class Problem115
    {
        public static void Main(string[] args)
        {
            new Problem115().Recursive();
        }

        long[] cache;

        public void Recursive()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long solutions = 0;
            int n = 50;

            int limit = 1000000;
            int m = n - 1;

            while (solutions < limit)
            {
                m++;
                cache = new long[m + 1];
                solutions = F(m, n);
            }

            clock.Stop();
            Console.WriteLine("The solutions exceeds {0} for m={1} ", limit, m);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void SaveCache()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long solutions = 0;
            int n = 50;

            int limit = 1000000;
            int m = n - 1;

            cache = new long[200];

            while (solutions < limit)
            {
                m++;
                solutions = F(m, n);
            }

            clock.Stop();
            Console.WriteLine("The solutions exceeds {0} for m={1} ", limit, m);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long F(int m, int n)
        {
            //The rest is empty
            long solutions = 1;

            //we can't fill out more
            if (n > m) return solutions;

            if (cache[m] != 0) return cache[m];

            for (int startpos = 0; startpos <= m - n; startpos++)
            {
                for (int blocklength = n; blocklength <= m - startpos; blocklength++)
                {
                    solutions += F(m - startpos - blocklength - 1, n);
                }
            }

            cache[m] = solutions;
            return solutions;
        }
    }
}
