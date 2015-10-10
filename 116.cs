using System;
using System.Diagnostics;

namespace euler
{
    class Problem116
    {
        public static void Main(string[] args)
        {
            new Problem116().Recursive();
        }

        long[] cache;

        public void Recursive()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long solutions = 0;
            int m = 50;
            int nmax = 4;
            int nmin = 2;

            for (int i = nmin; i <= nmax; i++)
            {
                cache = new long[m + 1];
                solutions += G(m, i);
            }

            clock.Stop();
            Console.WriteLine("You can fill a row of length {0} in {1} ways", m, solutions);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long G(int m, int n)
        {
            long solutions = 0;

            //we can't fill out more
            if (n > m) return solutions;

            if (cache[m] != 0) return cache[m];
            for (int startpos = 0; startpos <= m - n; startpos++)
            {
                solutions++; //We can fill in a block
                solutions += G(m - startpos - n, n);
            }

            cache[m] = solutions;
            return solutions;
        }
    }
}
