using System;
using System.Diagnostics;

namespace euler {
    class Problem129 {
        public static void Main(string[] args) {
            new Problem129().Bruteforce();
        }

        public void Bruteforce() {
            Stopwatch clock = Stopwatch.StartNew();
            
            int limit = 1000001;
            int n = limit;

            while (A(n) < limit) {                
                n += 2;
            }
                  
            clock.Stop();
            Console.WriteLine("The least value of n A(N) which first exceeds one-million {0}", n);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int A(int n) {
            if (GCD(n, 10) != 1) return 0;

            int x = 1;
            int k = 1;

            while (x != 0) {
                x = (x * 10 + 1) % n;
                k++;
            }

            return k;
        }

        private int GCD(int a, int b) {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
