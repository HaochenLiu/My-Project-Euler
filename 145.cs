using System;
using System.Diagnostics;

namespace euler
{
    class Problem145
    {
        public static void Main(string[] args)
        {
            new Problem145().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int count = 0;
            int limit = 1000000000;
            for (long i = 1; i < limit; i++)
            {
                if (isReversible(i)) count++;
            }

            clock.Stop();
            Console.WriteLine("There are {0} reversible numbers under {1}", count, limit);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void BruteforceCheckOdd()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int count = 0;
            int limit = 1000000000;
            for (long i = 1; i < limit; i += 2)
            {
                if (isReversible(i)) count += 2;

                if (i % 1000001 == 0) Console.WriteLine(i);
            }

            clock.Stop();
            Console.WriteLine("There are {0} reversible numbers under {1}", count, limit);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool isReversible(long n)
        {
            long number = n;

            //Check 0 in the end
            if (n % 10 == 0) return false;

            //Reverse the number
            long reversed = 0;
            while (number > 0)
            {
                reversed = 10 * reversed + number % 10;
                number /= 10;
            }

            //Add the original and reversed
            reversed += n;

            //Check if all digits are odd
            while (reversed > 0)
            {
                if ((reversed % 10) % 2 == 0) return false;
                reversed /= 10;
            }

            return true;
        }

        public void Analytic()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int count = 0;

            for (int i = 1; i < 10; i++)
            {
                switch (i % 4)
                {
                    case 0:
                    case 2:
                        count += 20 * (int)Math.Pow(30, (i / 2 - 1));
                        break;
                    case 1:
                        count += 100 * (int)Math.Pow(500, i / 4 - 1);
                        break;
                    case 3:
                        break;
                }

            }

            clock.Stop();
            Console.WriteLine("There are {0} reversible numbers under {1}", count, 1000000000);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
