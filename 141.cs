using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace euler
{
    class Problem141
    {
        public static void Main(string[] args)
        {
            new Problem141().Bruteforce();
        }
        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            long limit = (long)1e12;
            List<long> progressiveSquares = new List<long>();

            for (long a = 2; a < 10000; a++)
            {

                for (long b = 1; b < a; b++)
                {
                    if (a * a * a * b * b + b * b >= limit) break;
                    if (GCD(a, b) > 1) continue;

                    for (long c = 1; ; c++)
                    {
                        long n = a * a * a * b * c * c + c * b * b;
                        if (n >= limit) break;

                        if (IsSquare(n) && !progressiveSquares.Contains(n))
                        {
                            progressiveSquares.Add(n);
                        }

                    }
                }
            }

            long result = progressiveSquares.Sum();

            clock.Stop();
            Console.WriteLine("The sum of all progressive squares below {1}: {0}", result, limit);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private bool IsSquare(long n)
        {
            long root = (long)Math.Sqrt(n);
            return (root * root == n);
        }

        private long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
