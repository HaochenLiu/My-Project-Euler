using System;
using System.Diagnostics;

namespace euler
{
    class Problem142
    {
        public static void Main(string[] args)
        {
            new Problem142().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long a, b, c, d, e, f;
            bool solved = false;
            long result = 0;

            for (long i = 4; !solved; i++)
            {
                a = i * i;
                for (long j = 3; j < i && !solved; j++)
                {
                    c = j * j;
                    f = a - c;
                    if (f <= 0 || !IsSquare(f)) continue;


                    long kstart = (j % 2 == 1) ? 1 : 2;

                    for (long k = kstart; k < j; k += 2)
                    {
                        d = k * k;
                        e = a - d;
                        b = c - e;

                        if (b <= 0 || e <= 0 || !IsSquare(b) || !IsSquare(e)) continue;

                        long x = (d + c) / 2;
                        long y = (e + f) / 2;
                        long z = (c - d) / 2;

                        result = x + y + z;
                        solved = true;
                        break;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("The smallest x+y+z={0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool IsSquare(long n)
        {
            long root = (long)Math.Sqrt(n);
            return (root * root == n);
        }
    }
}
