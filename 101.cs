using System;
using System.Diagnostics;

namespace euler
{
    class Problem101
    {
        public static void Main(string[] args)
        {
            new Problem101().Lagrange();
        }

        public void Lagrange()
        {
            Stopwatch clock = Stopwatch.StartNew();

            //Generate the generator polynomial
            long[] coefficients = { 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1 };
            Polynomial poly = new Polynomial(coefficients);

            //Generate the points
            long[] y = new long[coefficients.Length];
            for (long i = 0; i < y.Length; i++)
            {
                y[i] = poly.evaluate(i + 1);
            }

            long fits = 0;
            for (long n = 1; n <= coefficients.Length - 1; n++)
            {
                long result = 0;
                for (long i = 1; i <= n; i++)
                {
                    long temp1 = 1;
                    long temp2 = 1;

                    for (long j = 1; j <= n; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }
                        else
                        {
                            temp1 *= n + 1 - j;
                            temp2 *= i - j;
                        }
                    }
                    result += temp1 * y[i - 1] / temp2;
                }

                fits += result;
                //Console.WriteLine(result);
            }

            clock.Stop();
            Console.WriteLine("The sum of FITs is {0}", fits);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }

    class Polynomial
    {
        private long[] coefficients;
        public long Degree;

        public Polynomial(long deg)
        {
            Degree = deg;
            coefficients = new long[deg + 1];
        }

        public Polynomial(long[] coefficients)
        {
            Degree = coefficients.Length - 1;
            this.coefficients = coefficients;
        }

        public long get(long i)
        {
            return coefficients[i];
        }

        public void set(long i, long value)
        {
            coefficients[i] = value;
        }

        public long evaluate(long x)
        {
            long result = 0;

            for (long i = this.Degree; i >= 0; i--)
            {
                result = result * x + get(i);
            }
            return result;
        }
    }
}
