using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading;

namespace PE
{
    class Program
    {
        public static long[] ESieve(int upperLimit)
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
            numbers.Add(2);

            for (int i = 1; i <= sieveBound; i++)
            {
                if (PrimeBits.Get(i))
                {
                    numbers.Add(2 * i + 1);
                }
            }

            return numbers.ToArray();
        }

        static void Main(string[] args)
        {
            long[] primes = ESieve(7071);
            long[][] powers = new long[3][];
            int target = 50000000;
            
            List<long> templist = new List<long>(primes);
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < primes.Length; i++)
                {
                    templist[i] *= primes[i];
                }
                powers[j] = templist.ToArray();
            }

            SortedSet<long> numbers = new SortedSet<long>();
            for (int i = 0; i < primes.Length; i++)
            {
                for (int j = 0; j < primes.Length; j++)
                {
                    for (int k = 0; k < primes.Length; k++)
                    {
                        long number = powers[0][i] + powers[1][j] + powers[2][k];
                        if (number > target) break;
                        numbers.Add(number);
                    }
                }
            }
            Console.Write(numbers.Count);
            Console.WriteLine();
        }
    }
}
