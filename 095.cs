using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Collections;

namespace euler
{
    class Problem095
    {
        public static void Main(string[] args)
        {
            new Problem095().Bruteforce();
        }

        private int[] primelist;

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 1000000;
            int result = 0;
            int chainLength = 0;

            primelist = ESieve(2, limit);

            bool[] numbers = new bool[limit + 1];

            for (int i = 2; i < limit + 1; i++)
            {
                if (numbers[i]) continue;
                List<int> chain = new List<int>();

                int newNumber = i;
                bool broken = false;

                while (!chain.Contains(newNumber))
                {
                    chain.Add(newNumber);
                    newNumber = sumOfFactors(newNumber);

                    if (newNumber > limit || numbers[newNumber])
                    {
                        broken = true;
                        break;
                    }
                }

                if (!broken)
                {
                    int smallest = int.MaxValue;
                    int first = chain.IndexOf(newNumber);

                    if (chain.Count - first > chainLength)
                    {
                        for (int j = first; j < chain.Count; j++)
                        {
                            if (chain[j] < smallest)
                                smallest = chain[j];
                        }

                        chainLength = chain.Count - first;
                        result = smallest;
                    }
                }

                for (int j = 0; j < chain.Count; j++)
                {
                    numbers[chain[j]] = true;
                }
            }

            clock.Stop();
            Console.WriteLine("The smallest number in the intest chain is {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int sumOfFactors(int number)
        {
            int n = number;
            int sum = 1;
            int p = primelist[0];
            int j;
            int i = 0;

            while (p * p <= n && n > 1)
            {
                p = primelist[i];
                i++;
                if (n % p == 0)
                {
                    j = p * p;
                    n = n / p;
                    while (n % p == 0)
                    {
                        j = j * p;
                        n = n / p;
                    }
                    sum = sum * (j - 1) / (p - 1);
                }
            }

            //A prime factor larger than the square root remains, so add that
            if (n > 1)
            {
                sum *= n + 1;
            }
            return sum - number;
        }

        public int[] ESieve(int lowerLimit, int upperLimit)
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

            List<int> numbers = new List<int>((int)(upperLimit / (Math.Log(upperLimit) - 1.08366)));

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

        int[] sumOfFactorsList;

        public void Sieve()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 1000000;
            int result = 0;
            int chainLength = 0;

            generateFactors(limit);

            bool[] numbers = new bool[limit + 1];

            for (int i = 2; i < limit + 1; i++)
            {
                if (numbers[i]) continue;
                List<int> chain = new List<int>();

                int newNumber = i;
                bool broken = false;

                while (!chain.Contains(newNumber))
                {
                    chain.Add(newNumber);
                    newNumber = sumOfFactorsList[newNumber];

                    if (newNumber > limit || numbers[newNumber])
                    {
                        broken = true;
                        break;
                    }
                }


                if (!broken)
                {
                    int smallest = int.MaxValue;
                    int first = chain.IndexOf(newNumber);

                    if (chain.Count - first > chainLength)
                    {
                        for (int j = first; j < chain.Count; j++)
                        {
                            if (chain[j] < smallest)
                                smallest = chain[j];
                        }

                        chainLength = chain.Count - first;
                        result = smallest;
                    }
                }

                for (int j = 0; j < chain.Count; j++)
                {
                    numbers[chain[j]] = true;
                }

            }

            clock.Stop();
            Console.WriteLine("The smallest number in the intest chain is {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private void generateFactors(int limit)
        {
            sumOfFactorsList = new int[limit + 1];
            for (int i = 1; i <= limit / 2; i++)
            {
                for (int j = 2 * i; j <= limit; j += i)
                {
                    sumOfFactorsList[j] += i;
                }
            }
        }
    }
}
