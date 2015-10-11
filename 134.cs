using System;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;

namespace euler
{
    class Problem134
    {
        public static void Main(string[] args)
        {
            new Problem134().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 1000000;
            int[] primes = Sieve(5, limit + 100);
            long result = 0;
            int i = 0;

            while (primes[i] <= limit)
            {
                //solve the linear congruence
                // 10^d(p1)*x + p1 == 0 (mod p2)                
                // 10^d(p1)*x == -p1 (mod p2)                
                // 10^d(p1)*x == p2-p1 (mod p2)                
                // ax == b mod n
                long p1 = primes[i];
                long p2 = primes[i + 1];

                long a = DigitCountFactor(p1);
                long b = p2 - p1;
                long n = p2;

                long[] rs = extended_gcd(a, n);
                long x = rs[0] * b % n;

                if (x < 0)
                    x = n + x;

                result += x * a + p1;
                i++;
            }

            clock.Stop();
            Console.WriteLine("Sum of S: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long DigitCountFactor(long number)
        {
            long factor = 1;

            while (number > 0)
            {
                factor *= 10;
                number /= 10;
            }

            return factor;
        }

        private long[] extended_gcd(long a, long b)
        {

            long x = 0;
            long lastx = 1;
            long y = 1;
            long lasty = 0;
            while (b != 0)
            {
                long quotient = a / b;

                long temp = b;
                b = a % b;
                a = temp;

                temp = x;
                x = lastx - quotient * x;
                lastx = temp;

                temp = y;
                y = lasty - quotient * y;
                lasty = temp;
            }

            return new long[] { lastx, lasty, a };
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
