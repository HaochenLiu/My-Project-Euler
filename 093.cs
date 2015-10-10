using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace euler
{
    class Problem93
    {
        public static void Main(string[] args)
        {
            new Problem93().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int[] best = null;
            int bestcount = 0;

            int[] comb = { 0, 1, 2, 3 };
            while (comb != null)
            {
                bool[] results = new bool[9 * 8 * 7 * 6];

                int[] perm = (int[])comb.Clone();

                while (perm != null)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                double? number = ope(ope(ope(perm[0], perm[1], i), perm[2], j), perm[3], k);
                                if (number != null && number == (int)number && number < results.Length && number > 0)
                                    results[(int)number] = true;

                                number = ope(ope(perm[0], ope(perm[1], perm[2], j), i), perm[3], k);
                                if (number != null && number == (int)number && number < results.Length && number > 0)
                                    results[(int)number] = true;

                                number = ope(perm[0], ope(ope(perm[1], perm[2], j), perm[3], k), i);
                                if (number != null && number == (int)number && number < results.Length && number > 0)
                                    results[(int)number] = true;

                                number = ope(perm[0], ope(perm[1], ope(perm[2], perm[3], k), j), i);
                                if (number != null && number == (int)number && number < results.Length && number > 0)
                                    results[(int)number] = true;

                                number = ope(ope(perm[0], perm[1], i), ope(perm[2], perm[3], k), j);
                                if (number != null && number == (int)number && number < results.Length && number > 0)
                                    results[(int)number] = true;
                            }
                        }
                    }

                    int l = 1;
                    while (results[l]) l++;

                    if (l > bestcount)
                    {
                        best = (int[])comb.Clone();
                        bestcount = l;
                    }

                    perm = getNextPerm(perm);
                }
                comb = getNextCombination(4, 10, comb);
            }

            clock.Stop();
            Console.Write("The best solution is ");
            for (int l = 0; l < best.Length; l++) Console.Write(best[l]);
            Console.WriteLine();
            Console.WriteLine("Which creates {0} solutions", bestcount);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private double? ope(double? a, double? b, int op)
        {
            if (a == null || b == null) return null;
            switch (op)
            {
                case 0:
                    return a + b;
                case 1:
                    return a - b;
                case 2:
                    return a * b;
                case 3:
                    if (b == 0) return null;
                    return a * 1.0 / b;
            }
            return 0;
        }

        public static int[] getNextCombination(int k, int n, int[] comb)
        {
            int i = k - 1;
            ++comb[i];
            while ((i > 0) && (comb[i] >= n - k + 1 + i))
            {
                --i;
                ++comb[i];
            }

            if (comb[0] > n - k)
                return null;

            for (i = i + 1; i < k; ++i)
                comb[i] = comb[i - 1] + 1;


            return comb;
        }

        public static int[] getNextPerm(int[] perm)
        {
            bool nextExist = false;
            for (int k = 0; k < perm.Length - 1; k++)
            {
                if (perm[k] < perm[k + 1]) nextExist = true;
            }
            if (!nextExist) return null;

            int N = perm.Length;
            int i = N - 1;

            while (perm[i - 1] >= perm[i])
            {
                i = i - 1;
            }

            int j = N;
            while (perm[j - 1] <= perm[i - 1])
            {
                j = j - 1;
            }

            // swap values at position i-1 and j-1
            swap(i - 1, j - 1, perm);

            i++;
            j = N;

            while (i < j)
            {
                swap(i - 1, j - 1, perm);
                i++;
                j--;
            }

            return perm;
        }

        private static void swap(int i, int j, int[] perm)
        {
            int k = perm[i];
            perm[i] = perm[j];
            perm[j] = k;
        }
    }
}
