using System;
using System.Diagnostics;

namespace euler
{
    class Problem124
    {
        public static void Main(string[] args)
        {
            new Problem124().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int target = 10000;
            int limit = 100000 + 1;

            Radical[] radicals = new Radical[limit];
            for (int i = 0; i < radicals.Length; i++)
            {
                radicals[i] = new Radical(1, i);
            }

            for (int i = 2; i < limit; i++)
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

            Array.Sort(radicals);

            //for (int i = 0; i < limit-1; i++) {
            //    Console.WriteLine(radicals[i].number + " " + radicals[i].rad + " " + (i + 1));                
            //}

            clock.Stop();
            Console.WriteLine("E({1}) = {0}", radicals[target].number, target);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private class Radical : IComparable
        {
            public int number, rad;

            public Radical(int rad, int number)
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
