using System;
using System.Diagnostics;

namespace euler
{
    class Problem126
    {
        public static void Main(string[] args)
        {
            new Problem126().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 30000;
            int[] count = new int[limit + 1];
            for (int z = 1; Cubes(z, z, z, 1) <= limit; ++z)
                for (int y = z; Cubes(z, y, z, 1) <= limit; ++y)
                    for (int x = y; Cubes(z, y, x, 1) <= limit; ++x)
                        for (int n = 1; Cubes(z, y, x, n) <= limit; ++n)
                            count[Cubes(z, y, x, n)]++;

            clock.Stop();
            Console.WriteLine("Minimal solution C({0})=1000", Array.IndexOf(count, 1000));
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int Cubes(int x, int y, int z, int n)
        {
            return 2 * (x * y + y * z + x * z) + 4 * (x + y + z + n - 2) * (n - 1);
        }
    }
}
