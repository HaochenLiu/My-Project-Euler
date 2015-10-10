using System;
using System.Diagnostics;

namespace euler
{
    class Problem114
    {
        public static void Main(string[] args)
        {
            new Problem114().Recursive();
        }

        long[] cache;

        public void Recursive()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int m = 50;
            int n = 3;
            cache = new long[m + 1];
            long solutions = F(m, n);

            clock.Stop();
            Console.WriteLine("The row can be filled in {0} ways ", solutions);
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
