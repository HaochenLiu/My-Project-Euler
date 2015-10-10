using System;
using System.Diagnostics;
using System.Numerics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace euler
{
    class Problem105
    {
        public static void Main(string[] args)
        {
            string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
            new Problem105().BruteForce(filename);
        }

        private bool Disjoint(int n, int m)
        {
            //Checks if the subsets are disjoint
            return (n & m) == 0;
        }

        private bool VerifyRule1(int[] a)
        {
            for (int i = 0; i < a.Length; i++)
            {
                int k = i;
                while (k != -1)
                {
                    k++;
                    if (k >= a.Length)
                        break;
                    k = Array.IndexOf(a, a[i], k);
                    if (k != -1 && Disjoint(i, k))
                        return false;
                }
            }
            return true;
        }
        
        private bool VerifyRule2(int[] a)
        {
            //Assume that the array is sorted
            int sum1 = a[0];
            int sum2 = 0;

            for (int i = 0; i < a.Length / 2; i++)
            {
                sum1 += a[i + 1];
                sum2 += a[a.Length - i - 1];

                if (sum1 <= sum2)
                    return false;
            }
            return true;
        }

        private int[] MakeSubsetSums(int[] a)
        {
            int[] b = new int[(int)Math.Pow(2, a.Length)];
            for (int i = 1; i < b.Length; i++)
            {
                b[i] = MakeSubsetSum(a, i);
            }
            return b;
        }

        private int MakeSubsetSum(int[] a, int m)
        {
            int sum = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if ((m & 1) == 1)
                {
                    sum += a[i];
                }
                m >>= 1;
            }
            return sum;
        }

        public void BruteForce(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew(); 
            
            int result = 0;
            int j = 0;
            string[] lines = File.ReadAllLines(filename);

            foreach (string line in lines)
            {
                //Parse the line
                string[] segments = line.Split(',');
                int dim = segments.Length;
                int[] numbers = new int[dim];
                for (int i = 0; i < dim; i++)
                {
                    numbers[i] = Convert.ToInt32(segments[i]);
                }

                Array.Sort(numbers);
                if (VerifyRule2(numbers))
                {
                    int[] s = MakeSubsetSums(numbers);
                    if (VerifyRule1(s))
                    {
                        result += numbers.Sum();
                        j++;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("The optimum sss string is {0} ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
