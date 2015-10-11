using System;
using System.Diagnostics;

namespace euler
{
    class Problem121
    {
        public static void Main(string[] args)
        {
            new Problem121().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 15;
            long[] outcomes = new long[limit + 1];
            outcomes[limit] = 1;
            outcomes[limit - 1] = 1;

            for (int i = 2; i <= limit; i++)
            {
                for (int j = 0; j < outcomes.Length - 1; j++)
                {
                    outcomes[j] = outcomes[j + 1];
                }
                outcomes[limit] = 0;

                for (int j = outcomes.Length - 1; j > 0; j--)
                {
                    outcomes[j] += outcomes[j - 1] * i;
                }
            }

            long positive = 0;
            for (int i = 0; i < limit / 2 + 1; i++)
            {
                positive += outcomes[i];
            }

            long total = 1;
            for (int i = 2; i < limit + 2; i++)
            {
                total *= i;
            }

            clock.Stop();
            Console.WriteLine("There are {0} positive outcomes out of {1}", positive, total);
            Console.WriteLine("This gives a prize allocation of {0}", total / positive);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
