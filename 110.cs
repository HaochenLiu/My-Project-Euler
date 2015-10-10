using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Collections;
using System.Numerics;

namespace euler
{
    class Problem110
    {
        public static void Main(string[] args)
        {
            new Problem110().Bruteforce();
        }

        int[] exponents;

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long[] primes = ESieve(2, 45);
            exponents = new int[primes.Length];

            //Find the absolute max we need
            BigInteger result = 1;
            for (int i = 0; i < primes.Length; i++)
            {
                result *= primes[i];
            }

            long limit = 2 * 4000000 - 1;
            int counter = 1;

            while (true)
            {
                Twos(limit);

                if (exponents[0] < exponents[1])
                {
                    //invalid combination
                    counter++;
                }
                else
                {
                    //The number of twos are larger than 
                    // number of threes, so good solution                    
                    BigInteger number = Number(primes, result);
                    if (number < result)
                        result = number;
                    counter = 1;
                }
                if (counter >= exponents.Length)
                    break;

                exponents[counter]++;
                SetAllSmallerExponents(counter);
            }

            clock.Stop();
            Console.WriteLine("The first n with more than {1} solutions is {0} ", result, (limit + 1) / 2);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public BigInteger Number(long[] primes, BigInteger result)
        {
            BigInteger number = 1;

            for (int i = 0; i < exponents.Length; i++)
            {
                if (exponents[i] == 0) break;
                number *= BigInteger.Pow(primes[i], exponents[i]);

                if (result < number)
                    return result + 1;
            }

            return number;
        }

        public void Twos(long limit)
        {
            exponents[0] = 0;
            long divisors = 1;

            for (int i = 0; i < exponents.Length; i++)
            {
                divisors *= 2 * exponents[i] + 1;
            }
            exponents[0] = (int)(limit / divisors - 1) / 2;

            while (divisors * (2 * exponents[0] + 1) < limit)
                exponents[0]++;
        }

        public void SetAllSmallerExponents(int exp)
        {
            for (int i = 0; i < exp; i++)
            {
                exponents[i] = exponents[exp];
            }
        }

        public long[] ESieve(int lowerLimit, int upperLimit)
        {

            int sieveBound = (int)(upperLimit - 1) / 2;
            int upperSqrt = ((int)Math.Sqrt(upperLimit) - 1) / 2;

            BitArray PrimeBits = new BitArray(sieveBound + 1, true);

            for (int i = 1; i <= upperSqrt; i++)
            {
                if (PrimeBits.Get(i))
                {
                    for (int j = i * 2 * (i + 1); j <= sieveBound; j += 2 * i + 1)
                    {
                        PrimeBits.Set(j, false);
                    }
                }
            }

            List<long> numbers = new List<long>((int)(upperLimit / (Math.Log(upperLimit) - 1.08366)));

            if (lowerLimit < 3)
            {
                numbers.Add(2);
                lowerLimit = 3;
            }

            for (int i = (lowerLimit - 1) / 2; i <= sieveBound; i++)
            {
                if (PrimeBits.Get(i))
                {
                    numbers.Add(2 * i + 1);
                }
            }

            return numbers.ToArray();
        }
    }
}
