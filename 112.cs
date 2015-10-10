using System;
using System.Diagnostics;

namespace euler
{
    class Problem112
    {
        public static void Main(string[] args)
        {
            new Problem112().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int i = 99;
            int bouncies = 0;

            while (100 * bouncies < 99 * i)
            {
                i++;
                if (isBouncy(i))
                    bouncies++;
            }

            clock.Stop();
            Console.WriteLine("We reach 99% at {0} ", i);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool isBouncy(int number)
        {

            bool inc = false;
            bool dec = false;

            int last = number % 10;
            number /= 10;

            while (number > 0)
            {
                int next = number % 10;
                number /= 10;
                if (next < last)
                    inc = true;
                else if (next > last)
                    dec = true;

                last = next;

                if (dec && inc) return true;
            }

            return dec && inc;
        }
    }
}
