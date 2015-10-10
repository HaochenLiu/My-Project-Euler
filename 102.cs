using System;
using System.Diagnostics;
using System.IO;

namespace euler
{
    class Problem102
    {
        public static void Main(string[] args)
        {
            string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
            new Problem102().BruteForce(filename);
        }

        public void BruteForce(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            string[] lines = File.ReadAllLines(filename);

            int result = 0;

            foreach (string line in lines)
            {
                //Parse the line
                string[] segments = line.Split(',');
                int[,] coordinates = new int[2, segments.Length / 2];

                int[] A = { Convert.ToInt32(segments[0]), Convert.ToInt32(segments[1]) };
                int[] B = { Convert.ToInt32(segments[2]), Convert.ToInt32(segments[3]) };
                int[] C = { Convert.ToInt32(segments[4]), Convert.ToInt32(segments[5]) };
                int[] P = { 0, 0 };

                if (area(A, B, C) == area(A, B, P) + area(A, P, C) + area(P, B, C))
                    result++;
            }

            clock.Stop();
            Console.WriteLine("The number of Triangles containing (0,0): {0} ", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int area(int[] a, int[] b, int[] c)
        {
            return Math.Abs((a[0] - c[0]) * (b[1] - a[1]) - (a[0] - b[0]) * (c[1] - a[1]));
        }
    }
}
