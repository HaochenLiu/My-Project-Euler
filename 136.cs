using System;
using System.Diagnostics;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace euler
{
    class Problem136
    {
        public static void Main(string[] args)
        {
            new Problem136().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int n = 50000000;
            int[] solutions = new int[n + 1];

            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; u * v <= n; v++)
                {

                    if ((u + v) % 4 == 0 &&
                        3 * v > u &&
                        ((3 * v - u) % 4) == 0)
                        solutions[u * v]++;
                }
            }

            int result = solutions.Where(x => x == 1).Count();

            clock.Stop();
            Console.WriteLine("number of values with exactly 1 solution: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Bruteforce2()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int n = 50000000;
            int result = 2; //take care of the cases n= 4, n = 16
            int[] primes = Sieve(1, n);

            for (int i = 1; i < primes.Length; i++)
            {
                if (primes[i] < n / 4)
                    result++;

                if (primes[i] < n / 16)
                    result++;

                if ((primes[i] - 3) % 4 == 0)
                    result++;
            }

            clock.Stop();
            Console.WriteLine("number of values with exactly 1 solution: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public int[] Sieve(int lowerLimit, int upperLimit)
        {
            if (lowerLimit > upperLimit)
            {
                return new int[0];
            }

            upperLimit = Math.Max(upperLimit, 1);

            int sieveBound = (int)(upperLimit - 1) / 2;
            int upperSqrt = ((int)Math.Sqrt(upperLimit) - 1) / 2;

            BitArray isPrime = new BitArray(sieveBound + 1, true);

            for (int i = 1, ii = 3, iii = 4; i <= upperSqrt; i++, ii += 2, iii += 4 * i)
            {
                if (isPrime.Get(i))
                {
                    for (int j = iii; j <= sieveBound; j += ii)
                    {
                        isPrime.Set(j, false);
                    }
                }
            }

            List<int> primes = new List<int>(Math.Max(Math.Min((int)(upperLimit / (Math.Log(upperLimit) - 1.08366)), upperLimit), 10));

            if (lowerLimit < 3 && upperLimit >= 2)
            {
                primes.Add(2);
            }

            if (lowerLimit < 3)
            {
                lowerLimit = 3;
            }

            for (int i = lowerLimit / 2, ii = 2 * i + 1; i <= sieveBound; i++, ii += 2)
            {
                if (isPrime.Get(i))
                {
                    primes.Add(ii);
                }
            }

            return primes.ToArray();
        }
    }
}
