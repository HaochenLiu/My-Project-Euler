using System;
using System.Diagnostics;
using System.Numerics;

namespace euler
{
    class Problem111
    {
        public static void Main(string[] args)
        {
            new Problem111().Bruteforce();
        }

        int[] number = new int[10];

        private long CheckNumber()
        {
            if (number[0] == 0) return 0;
            long n = 0;

            for (int i = 0; i < number.Length; i++)
            {
                n = n * 10 + number[i];
            }

            if (IsProbablePrime(n, new int[] { 2, 3, 5, 7, 11 }))
                Console.WriteLine(n);

            return IsProbablePrime(n, new int[] { 2, 3, 5, 7, 11 }) ? n : 0;
        }

        private long Recurse(int basedigit, int startpos, int level, bool fill = false)
        {
            if (level <= 0) return CheckNumber();
            long res = 0;
            if (fill)
            {
                for (int pos = 0; pos < number.Length; pos++)
                {
                    number[pos] = basedigit;
                }
            }
            for (int pos = startpos; pos < number.Length; pos++)
            {
                for (int val = 0; val < 10; val++)
                {
                    number[pos] = val;
                    res += Recurse(basedigit, pos + 1, level - 1);
                    number[pos] = basedigit;
                }
            }
            return res;
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;
            for (int d = 0; d < 10; d++)
            {
                for (int i = 1; i < number.Length; i++)
                {
                    long sum = Recurse(d, 0, i, true);
                    if (sum > 0)
                    {
                        result += sum;
                        break;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("S(10,d) = {0}  ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
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
        public bool IsProbablePrime(BigInteger n, int[] ar)
        {
            if (n <= 1)
                return false;
            if (n == 2)
                return true;
            if (n % 2 == 0)
                return false;
            if (n < 9)
                return true;
            if (n % 3 == 0)
                return false;
            if (n % 5 == 0)
                return false;

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
    }
}
