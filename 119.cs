using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;

namespace euler
{
    class Problem119
    {
        public static void Main(string[] args)
        {
            new Problem119().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            List<BigInteger> a = new List<BigInteger>();

            for (int b = 2; b < 400; b++)
            {
                BigInteger value = b;
                for (int e = 2; e < 50; e++)
                {
                    value *= b;

                    if (DigitSum(value) == b)
                    {
                        a.Add(value);
                        //Console.WriteLine("b = {0}, e={1}, number = {2}", b, e, value);
                    }
                    if (a.Count > 50) break;
                }
                if (a.Count > 50) break;
            }


            a.Sort();

            clock.Stop();
            Console.WriteLine("a30 is {0}", a[29]);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int DigitSum(BigInteger n)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += (int)BigInteger.Remainder(n, 10);
                n /= 10;
            }

            return sum;
        }
    }
}
