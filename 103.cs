using System;
using System.Diagnostics;


namespace euler
{
    class Problem103
    {
        public static void Main(string[] args)
        {
            new Problem103().BruteForce();
        }

        public void BruteForce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            // base vector            
            int[] a = new int[] { 20, 31, 38, 39, 40, 42, 45 };
            int min = -3;
            int max = 3;
            string result = "";


            int[] t = new int[a.Length];
            int dim = a.Length;
            int[] s; // sum vector
            int[] c = new int[7]; // pertubation vector            
            for (int i = 0; i < c.Length; i++)
            {
                c[i] = min;
            }

            int tsum = 0;
            int tmin = int.MaxValue;

            for (int i = 0; i < (int)Math.Pow(max - min + 1, dim); i++)
            {
                for (int j = 0; j < a.Length; j++)
                {
                    t[j] = a[j] + c[j];
                }
                tsum = TotSum(t);

                if (tsum <= tmin)
                {
                    Array.Sort(t);
                    if (VerifyRule2(t))
                    {

                        s = MakeSubsetSums(t);
                        if (VerifyRule1(s, dim))
                        {
                            tmin = tsum;
                            result = PrintVect(t);
                        }
                    }
                }

                c = UpdatePertubationVector(c, min, max);
            }

            clock.Stop();
            Console.WriteLine("The optimum sss string is {0} ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
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

        private string PrintVect(int[] a)
        {
            string s = "";
            for (int i = 0; i < a.Length; i++)
            {
                s += a[i];
            }
            return s;
        }

        private int TotSum(int[] a)
        {
            int sum = 0;
            for (int i = 0; i < a.Length; i++)
            {
                sum += a[i];
            }
            return sum;
        }

        private int[] UpdatePertubationVector(int[] a, int min, int max)
        {
            for (int i = a.Length - 1; i >= 0; i--)
            {
                if (a[i] == max) continue;
                else
                {
                    for (int j = i + 1; j < a.Length; j++)
                    {
                        a[j] = min;
                    }
                    a[i]++;
                    return a;
                }
            }
            return a;
        }

        private bool VerifyRule1(int[] a, int dim)
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

        private bool Disjoint(int n, int m)
        {
            //Checks if the subsets are disjoint
            return (n & m) == 0;
        }
    }
}
