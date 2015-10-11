using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace euler
{
    class Problem143
    {
        public static void Main(string[] args)
        {
            new Problem143().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 120000;
            int limitSQ = 347;

            List<Tuple<int, int>> pairs = new List<Tuple<int, int>>();

            for (int u = 1; u < limitSQ; u++)
            {
                for (int v = 1; v < u; v++)
                {
                    if (GCD(u, v) != 1) continue;
                    if ((u - v) % 3 == 0) continue;

                    int a = 2 * u * v + v * v;
                    int b = u * u - v * v;

                    if (a + b > limit) break;
                    for (int k = 1; k * (a + b) < limit; k++)
                    {
                        pairs.Add(new Tuple<int, int>(k * a, k * b));
                        pairs.Add(new Tuple<int, int>(k * b, k * a));
                    }
                }
            }

            pairs.Sort();

            // Create index
            int[] index = Enumerable.Repeat(-1, limit).ToArray<int>();

            for (int i = 0; i < pairs.Count; i++)
            {
                if (index[pairs[i].Item1] == -1)
                    index[pairs[i].Item1] = i;
            }

            bool[] sums = new bool[limit];

            for (int i = 0; i < pairs.Count; i++)
            {
                int a = pairs[i].Item1;
                int b = pairs[i].Item2;

                List<int> va = new List<int>();
                List<int> vb = new List<int>();

                for (int j = index[a]; j < pairs.Count; j++)
                {
                    Tuple<int, int> next = pairs[j];
                    if (next.Item1 != a) break;
                    va.Add(next.Item2);
                }

                for (int j = index[b]; j < pairs.Count; j++)
                {
                    Tuple<int, int> next = pairs[j];
                    if (next.Item1 != b) break;
                    vb.Add(next.Item2);
                }

                for (int ja = 0; ja < va.Count; ja++)
                {
                    if (vb.IndexOf(va[ja]) != -1 && a + b + va[ja] < limit)
                    {
                        sums[a + b + va[ja]] = true;
                    }
                }
            }

            long result = 0;
            for (int i = 0; i < limit; i++)
            {
                if (sums[i])
                    result += i;
            }

            clock.Stop();
            Console.WriteLine("The sums of torecelli triangles is: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int GCD(int a, int b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
