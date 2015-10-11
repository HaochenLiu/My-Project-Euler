using System;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;

namespace euler
{
    class Problem146
    {
        public static void Main(string[] args)
        {
            new Problem146().Bruteforce();
            new Problem146().Bjarki();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long limit = 150000000;
            long result = 0;

            for (long i = 10; i <= limit; i += 10)
            {
                long squared = i * i;

                if (squared % 3 != 1) continue;
                if (squared % 7 != 2 && squared % 7 != 3) continue;

                if (squared % 9 == 0 ||
                    squared % 13 == 0 ||
                    squared % 27 == 0)
                    continue;

                if (IsProbablePrime(squared + 1) &&
                    IsProbablePrime(squared + 3) &&
                    IsProbablePrime(squared + 7) &&
                    IsProbablePrime(squared + 9) &&
                    IsProbablePrime(squared + 13) &&
                    IsProbablePrime(squared + 27) &&
                   !IsProbablePrime(squared + 19) &&
                   !IsProbablePrime(squared + 21))
                    result += i;

                if (i % 1000000 == 0) Console.WriteLine(i);
            }

            clock.Stop();
            Console.WriteLine("The sum of such integers below {1} is {0}", result, limit);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Bjarki()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 150000000;

            long result = 0;
            int[] primes = Sieve(2, 5000);
            Tuple<int, bool[]>[] mods = new Tuple<int, bool[]>[primes.Length];

            for (int i = 0; i < primes.Length; i++)
            {
                mods[i] = new Tuple<int, bool[]>(primes[i], Mods(primes[i]));
            }

            for (long i = 10; i < limit; i += 10)
            {
                bool ok = true;
                for (int j = 0; ok && j < primes.Length && i * i > primes[j]; j++)
                {
                    ok = mods[j].Item2[i % mods[j].Item1];
                }

                for (int j = 0; ok && j < Add.Length; j++)
                {
                    ok = IsProbablePrime(i * i + Add[j]);
                }

                for (int j = 0; ok && j < NotAdd.Length; j++)
                {
                    ok = !IsProbablePrime(i * i + NotAdd[j]);
                }

                if (ok)
                {
                    // Console.WriteLine(i);
                    result += i;
                }
            }

            clock.Stop();
            Console.WriteLine("The sum of such integers below {1} is {0}", result, limit);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public static int[] Add = new int[] { 1, 3, 7, 9, 13, 27 };
        public static int[] NotAdd = new int[] { 19, 21 };

        public bool[] Mods(int m)
        {
            bool[] res = new bool[m];
            for (int i = 0; i < m; i++)
            {
                res[i] = true;
                for (int j = 0; j < Add.Length; j++)
                {
                    if ((i * i + Add[j]) % m == 0)
                    {
                        res[i] = false;
                        break;
                    }
                }
            }

            return res;
        }

        private static readonly BigInteger LimitA = 1373653;
        private static readonly BigInteger LimitB = 9080191;
        private static readonly BigInteger LimitC = 4759123141L;
        private static readonly BigInteger LimitD = 2152302898747L;
        private static readonly BigInteger LimitE = 3474749660383L;

        /// <summary>
        /// Determines whether the specified number is probably prime.
        /// </summary>
        /// <param name="n">The specifed number.</param>
        /// <returns>
        ///   <c>true</c> if the specified number is probably prime; otherwise, <c>false</c>.
        /// </returns>
        public bool IsProbablePrime(long n)
        {
            if (n < LimitA) return IsProbablePrime(n, new int[] { 2, 3 });
            if (n < LimitB) return IsProbablePrime(n, new int[] { 31, 73 });
            if (n < LimitC) return IsProbablePrime(n, new int[] { 2, 7, 61 });
            if (n < LimitD) return IsProbablePrime(n, new int[] { 2, 3, 5, 7, 11 });
            if (n < LimitE) return IsProbablePrime(n, new int[] { 2, 3, 5, 7, 11, 13 });

            return IsProbablePrime(n, new int[] { 2, 3, 5, 7, 11, 13, 17 });
        }

        /// <summary>
        /// Returns a boolean to tell if the number is probable prime
        /// It is an implementation of the Rabin-Miller test
        /// In order to get a real prime the choice of ar should be made as
        /// if n < 1,373,653, it is enough to test ar = {2, 3};
        /// if n < 9,080,191, it is enough to test ar = {31, 73};
        /// if n < 4,759,123,141, it is enough to test ar = {2, 7, 61};
        /// if n < 2,152,302,898,747, it is enough to test ar = {2, 3, 5, 7, 11};
        /// if n < 3,474,749,660,383, it is enough to test ar = {2, 3, 5, 7, 11, 13};
        /// if n < 341,550,071,728,321, it is enough to test ar = {2, 3, 5, 7, 11, 13, 17}.
        /// </summary>
        public bool IsProbablePrime(long n, int[] ar)
        {

            for (int i = 0; i < ar.Length; i++)
            {
                if (Witness(ar[i], n))
                    return false;
            }
            return true;
        }

        private bool Witness(int a, BigInteger n)
        {
            int t = 0;
            BigInteger u = n - 1;
            while ((u & 1) == 0)
            {
                t++;
                u >>= 1;
            }

            BigInteger xi1 = BigInteger.ModPow(a, u, n);
            BigInteger xi2;

            for (int i = 0; i < t; i++)
            {
                xi2 = xi1 * xi1 % n;
                if ((xi2 == 1) && (xi1 != 1) && (xi1 != (n - 1)))
                    return true;
                xi1 = xi2;
            }
            if (xi1 != 1)
                return true;
            return false;
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
