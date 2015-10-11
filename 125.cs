using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace euler
{
    class Problem125
    {
        public static void Main(string[] args)
        {
            new Problem125().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 100000000;
            double sqrtLimit = Math.Sqrt(limit);

            long sum = 0;
            SortedSet<int> list = new SortedSet<int>();

            for (int i = 1; i <= sqrtLimit; i++)
            {
                int number = i * i;
                for (int j = i + 1; j <= sqrtLimit; j++)
                {
                    number += j * j;
                    if (number > limit) break;

                    if (IsPalindrome(number) && !list.Contains(number))
                    {
                        sum += number;
                        list.Add(number);
                    }

                }
            }

            clock.Stop();
            Console.WriteLine("sum of palindromic squares = {0}", sum);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool IsPalindrome(int number)
        {
            int reversed = 0;
            int k = number;

            while (k > 0)
            {
                reversed = 10 * reversed + k % 10;
                k /= 10;
            }
            return number == reversed;
        }
    }
}
