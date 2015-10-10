using System;
using System.Diagnostics;
using System.IO;
using System.Numerics;

namespace euler
{
    class Problem099
    {
        public static void Main(string[] args)
        {
            string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
            //new Problem099().Bigint(filename);
            new Problem099().Logarithm(filename);
        }

        public void Bigint(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            int maxline = 0;
            BigInteger maxnum = 0;
            string[] lines = File.ReadAllLines(filename);

            for (int i = 0; i < lines.Length; i++)
            {
                Console.Write(i + ":");

                string[] line = lines[i].Split(',');
                int basenum = Convert.ToInt32(line[0]);
                int exponent = Convert.ToInt32(line[1]);

                Console.Write(" Converted");

                BigInteger number = BigInteger.Pow(basenum, exponent);

                Console.Write(", Calculated");

                if (number > maxnum)
                {
                    maxline = i;
                    maxnum = number;
                }
                Console.WriteLine(", Compared!");
                break;
            }

            clock.Stop();
            Console.WriteLine("The line with the largest number is {0}", maxline);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Logarithm(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            int maxline = 0;
            double maxnum = 0;
            string[] lines = File.ReadAllLines(filename);
            for (int i = 0; i < lines.Length; i++)
            {
                string[] line = lines[i].Split(',');
                double basenum = Math.Log(Convert.ToInt32(line[0]));
                int exponent = Convert.ToInt32(line[1]);

                double number = basenum * exponent;

                if (number > maxnum)
                {
                    maxline = i + 1;
                    maxnum = number;
                }

            }

            clock.Stop();
            Console.WriteLine("The line with the largest number is {0}", maxline);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
