using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace euler
{
    class Problem118
    {
        public static void Main(string[] args)
        {
            new Problem118().Bruteforce();
        }

        int[] perm = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int count = 0;

            do
            {
                count += CheckPartitions(0, 0);
            } while (nextPermuation());

            clock.Stop();
            Console.WriteLine("There are {0} sets", count);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool nextPermuation()
        {
            int N = perm.Length;
            int i = N - 1;

            while (perm[i - 1] >= perm[i])
            {
                i = i - 1;
                if (i == 0)
                    return false;

            }

            int j = N;
            while (perm[j - 1] <= perm[i - 1])
            {
                j = j - 1;
            }

            // swap values at position i-1 and j-1
            swap(i - 1, j - 1);

            i++;
            j = N;

            while (i < j)
            {
                swap(i - 1, j - 1);
                i++;
                j--;
            }

            return true;
        }

        private void swap(int i, int j)
        {
            int k = perm[i];
            perm[i] = perm[j];
            perm[j] = k;
        }

        private int CheckPartitions(int startIndex, int prev)
        {
            int count = 0;
            for (int i = startIndex; i < perm.Length; i++)
            {

                //form the number x of the digits startIndex -> i
                int number = 0;
                for (int j = startIndex; j <= i; j++)
                {
                    number = number * 10 + perm[j];
                }

                //We only count ordered sets, so check that the current number is larger than the previous
                if (number < prev) continue;

                //Check that number is prime 
                if (!IsPrime(number)) continue;

                // No more digits so return
                if (i == (perm.Length - 1)) return count + 1;

                count += CheckPartitions(i + 1, number);
            }

            return count;
        }

        public bool IsPrime(int n)
        {
            if (n < 2)
                return false;
            if (n < 4)
                return true;
            if (n % 2 == 0)
                return false;
            if (n < 9)
                return true;
            if (n % 3 == 0)
                return false;
            if (n < 25)
                return true;

            int s = (int)Math.Sqrt(n);
            for (int i = 5; i <= s; i += 6)
            {
                if (n % i == 0)
                    return false;
                if (n % (i + 2) == 0)
                    return false;
            }

            return true;
        }
    }
}
