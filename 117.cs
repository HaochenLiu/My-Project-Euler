using System;
using System.Diagnostics;

namespace euler
{
    class Problem117
    {
        public static void Main(string[] args)
        {
            new Problem117().Recursive();
        }

        long[] cache;

        public void Recursive()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int m = 50;
            int nmax = 4;
            int nmin = 2;

            cache = new long[m + 1];

            long solutions = F(m, nmin, nmax);

            clock.Stop();
            Console.WriteLine("You can fill a row of length {0} in {1} ways", m, solutions);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long F(int m, int nmin, int nmax)
        {
            //The rest is empty
            long solutions = 1;

            //we can't fill out more
            if (nmin > m) return solutions;

            if (cache[m] != 0) return cache[m];
            for (int bs = nmin; bs <= nmax; bs++)
            {
                for (int startpos = 0; startpos <= m - bs; startpos++)
                {
                    solutions += F(m - startpos - bs, nmin, nmax);
                }
            }

            cache[m] = solutions;
            return solutions;
        }
    }
}
