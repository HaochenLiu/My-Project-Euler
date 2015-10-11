using System;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;

namespace euler
{
    class Problem123
    {
        public static void Main(string[] args)
        {
            new Problem123().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long limit = 10000000000;
            BigInteger r = 0;
            int[] primes = Sieve(2, 500000);
            int n = 7037;

            while (r < limit)
            {
                n += 2;
                BigInteger p = primes[n - 1];
                r = 2 * p * n;
            }

            clock.Stop();
            Console.WriteLine("The least value of n = {0}", n);
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
