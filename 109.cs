using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Collections;

namespace euler
{
    class Problem109
    {
        public static void Main(string[] args)
        {
            new Problem109().Bruteforce();
        }

        public void Bruteforce()
        {
            Stopwatch clock = Stopwatch.StartNew();

            int limit = 100;
            int result = 0;

            List<int> scores = new List<int>();

            //build all possible single dart scores
            for (int i = 1; i <= 20; i++)
            {
                scores.Add(i);
                scores.Add(2 * i);
                scores.Add(3 * i);
            }
            scores.Add(25);
            scores.Add(50);

            //make all the possible doubles
            List<int> doubles = new List<int>();
            for (int i = 1; i <= 20; i++)
            {
                doubles.Add(2 * i);
            }
            doubles.Add(25 * 2);

            //Count all miss, miss, double
            foreach (int third in doubles)
            {
                if (third < limit)
                    result++;
            }

            //count all miss, hit, double
            for (int i = 0; i < scores.Count; i++)
            {
                foreach (int third in doubles)
                {
                    if (scores[i] + third < limit)
                        result++;
                }
            }

            //count all hit, hit, double            
            for (int i = 0; i < scores.Count; i++)
            {
                for (int j = i; j < scores.Count; j++)
                {
                    foreach (int third in doubles)
                    {
                        if (scores[i] + scores[j] + third < limit)
                            result++;
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("There are {0} ways to checkout", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }
    }
}
