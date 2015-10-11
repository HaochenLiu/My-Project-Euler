using System;
using System.Diagnostics;

namespace euler
{
    class Problem127
    {
        public static void Main(string[] args)
        {
            new Problem127().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;
            long limit = 120000;

            //Sieve all radicals
            long[] radicals = new long[limit + 1];
            for (long i = 0; i < radicals.Length; i++)
            {
                radicals[i] = 1;
            }

            for (long i = 2; i < limit; i++)
            {
                if (radicals[i] == 1)
                {
                    radicals[i] = i;

                    for (long j = i + i; j < limit; j += i)
                    {
                        radicals[j] *= i;
                    }
                }
            }

            //Check for the properties
            for (long a = 1; a < limit; a++)
            {
                for (long b = a + 1; b < limit - a; b++)
                {
                    if (radicals[a] * radicals[b] * radicals[a + b] >= a + b) continue;
                    if (GCD(a, b) != 1) continue;
                    result += a + b;
                    //Console.WriteLine(a + " " + b + " " + (a + b));
                }
                //if (a % 1000 == 0) Console.WriteLine(a);

            }

            clock.Stop();
            Console.WriteLine("sum of c = {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        public void Bruteforce2()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long result = 0;
            long limit = 120000;


            Radical[] radicals = new Radical[limit + 1];
            for (int i = 0; i < radicals.Length; i++)
            {
                radicals[i] = new Radical(1, i);
            }

            for (int i = 2; i <= limit; i++)
            {
                if (radicals[i].rad == 1)
                {
                    radicals[i].rad = i;

                    for (int j = i + i; j < limit; j += i)
                    {
                        radicals[j].rad *= i;
                    }
                }
            }

            Radical[] sortedRadicals = new Radical[limit];
            Array.Copy(radicals, 1, sortedRadicals, 0, limit);
            Array.Sort(sortedRadicals);

            for (long c = 3; c <= limit; c++)
            {
                long radc = radicals[c].rad;
                long chalf = c / 2;

                foreach (var a in sortedRadicals)
                {
                    if (a.rad * radicals[c].rad > chalf) break;
                    if (a.number >= chalf) continue;

                    long b = c - a.number;
                    if (a.rad * radicals[b].rad * radc < c && GCD(a.rad, radicals[b].rad) == 1)
                        result += c;
                }
            }

            clock.Stop();
            Console.WriteLine("sum of c = {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private class Radical : IComparable
        {
            public long number, rad;

            public Radical(long rad, long number)
            {
                this.number = number;
                this.rad = rad;
            }

            int IComparable.CompareTo(object x)
            {
                Radical other = x as Radical;

                if (this.rad > other.rad) return 1;
                if (this.rad < other.rad) return -1;
                return this.number > other.number ? 1 : -1;
            }
        }
    }
}
