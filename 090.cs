using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading;
using System.IO;
using System.Text.RegularExpressions;

namespace PE
{
    class Program
    {
        private static List<List<int>> allCombination(int k, int n)
        {
            List<List<int>> combs = new List<List<int>>();
            List<int> comb = new List<int>();
            for (int i = 0; i < k; i++) {
                comb.Add(i);
            }
            while (true) {
                combs.Add(comb);
                //create new array with old solution
                comb = new List<int>(comb);
 
                //Substitute 9 with 6 in the last solution
                if (combs[combs.Count - 1][k - 1] == 9)
                    combs[combs.Count - 1][k - 1] = 6;
 
                int i = k - 1;
                ++comb[i];
                while ((i > 0) && (comb[i] >= n - k + 1 + i)) {
                    --i;
                    ++comb[i];
                }
 
                if (comb[0] > n - k)
                    break;
 
                for (i = i + 1; i < k; ++i)
                    comb[i] = comb[i - 1] + 1;
            }
 
            return combs;
        }

        private static bool isValidCombinations(List<int> d1, List<int> d2)
        {
            int[,] combs = {{0, 1}, {0, 4}, {0, 6}, {1, 6}, {2, 5}, {3, 6}, {4, 6}, {6, 4}, {8, 1}};

            bool valid = true;
            for (int i = 0; i < combs.GetLength(0); i++)
            {
                if (!((d1.Contains(combs[i, 0]) && d2.Contains(combs[i, 1])) ||
                    (d2.Contains(combs[i, 0]) && d1.Contains(combs[i, 1]))))
                {
                    valid = false;
                    break;
                }
            }
            return valid;
        }

        static void Main(string[] args)
        {
            int result = 0;
            List<List<int>> combs = allCombination(6, 10);
            for (int i = 0; i < combs.Count; i++)
            {
                if (combs[i][0] != 0) break;
                for (int j = i + 1; j < combs.Count; j++)
                {
                    if (isValidCombinations(combs[i], combs[j]))
                    {
                        result++;
                    }
                }
            } 
            Console.Write(result);
            Console.WriteLine();
        }
    }
}
