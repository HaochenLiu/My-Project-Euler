using System;
using System.Diagnostics;

namespace euler
{
    class Problem144
    {
        public static void Main(string[] args)
        {
            new Problem144().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;

            double xA = 0.0;
            double yA = 10.1;

            double xO = 1.4;
            double yO = -9.6;

            while (xO > 0.01 || xO < -0.01 || yO < 0)
            {
                //Calculate the slope of A
                double slopeA = (yO - yA) / (xO - xA);

                //Calculate the slope of the ellipse tangent
                double slopeO = -4 * xO / yO;

                //Calculate the slope of B
                double tanA = (slopeA - slopeO) / (1 + slopeA * slopeO);
                double slopeB = (slopeO - tanA) / (1 + tanA * slopeO);

                //calculate intercept of line B
                double interceptB = yO - slopeB * xO;

                //solve the quadratic equation for finding the intersection of B and the ellipse
                // a*x^2 + b*x + c = 0
                double a = 4 + slopeB * slopeB;
                double b = 2 * slopeB * interceptB;
                double c = interceptB * interceptB - 100;

                double ans1 = (-b + Math.Sqrt(b * b - 4 * a * c)) / (2 * a);
                double ans2 = (-b - Math.Sqrt(b * b - 4 * a * c)) / (2 * a);

                xA = xO;
                yA = yO;

                //Take the solution which is furtherst from x0
                xO = (Math.Abs(ans1 - xO) > Math.Abs(ans2 - xO)) ? ans1 : ans2;
                yO = slopeB * xO + interceptB;

                result++;
            }

            clock.Stop();
            Console.WriteLine("The number of bounces is: {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
