using System;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;

namespace euler
{
    class Problem133
    {
        public static void Main(string[] args)
        {
            new Problem133().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;
            int[] primes = Sieve(2, 100000);
            BigInteger k = BigInteger.Pow(10, 16);

            for (int i = 0; i < primes.Length; i++)
            {
                if (BigInteger.ModPow(10, k, 9 * primes[i]) != 1)
                    result += primes[i];
            }

            clock.Stop();
            Console.WriteLine("Sum of the primes not divisible not a factor of R(10^n): {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Factoring()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 10;
            int[] primes = Sieve(6, 100000);

            for (int i = 0; i < primes.Length; i++)
            {
                if (OtherFactor(A(primes[i])))
                {
                    result += primes[i];
                }
            }

            clock.Stop();
            Console.WriteLine("Sum of the primes not divisible not a factor of R(10^n): {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool OtherFactor(int k)
        {
            int[] factors = new int[] { 2, 5 };
            int i = 0;

            while (i < factors.Length && k > 1)
            {
                if (k % factors[i] == 0)
                {
                    k = k / factors[i];
                }
                else
                {
                    i++;
                }
            }

            return k > 1;
        }

        private int A(int n)
        {
            int x = 1;
            int k = 1;

            while (x != 0)
            {
                x = (x * 10 + 1) % n;
                k++;
            }

            return k;
        }

        /// <summary>
        /// Returns an array of primes up to upperLimit.
        /// </summary>
        /// <remarks>Efficient Sieve of Eratosthenes.</remarks>
        public static int[] Sieve(int lowerLimit, int upperLimit)
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
