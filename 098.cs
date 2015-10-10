using System;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace euler
{
    class Problem098
    {
        public static void Main(string[] args)
        {
            string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
            new Problem098().BruteForce(filename);
            new Problem098().Hashing(filename);
        }

        int[] squares;
        public void BruteForce(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;

            List<int> squareList = new List<int>();
            for (int i = 2; i < 31700; i++)
            {
                squareList.Add(i * i);
            }
            squares = squareList.ToArray();

            string[] words = File.ReadAllText(filename).Replace("\"", "").Split(',');
            char[][] sorted = new char[words.Length][];

            //Find anagrams
            for (int i = 0; i < words.Length; i++)
            {
                sorted[i] = words[i].ToCharArray();
                Array.Sort(sorted[i]);
            }

            for (int i = 0; i < words.Length; i++)
            {
                for (int j = i + 1; j < words.Length; j++)
                {
                    if (sorted[i].Length != sorted[j].Length) continue;
                    bool isEqual = true;
                    for (int k = 0; k < sorted[i].Length; k++)
                    {
                        isEqual = sorted[i][k] == sorted[j][k];
                        if (!isEqual) break;
                    }

                    if (isEqual)
                    {
                        int pairvalue = SquareAnagram(words[i], words[j]);

                        if (pairvalue > result)
                            result = pairvalue;
                        //Console.WriteLine("{0} and {1} are anagrams and gives {2}", words[i], words[j], pairvalue);
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("The largest square number is {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public void Hashing(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            int result = 0;

            List<int> squareList = new List<int>();
            for (int i = 2; i < 31700; i++)
            {
                squareList.Add(i * i);
            }
            squares = squareList.ToArray();

            Dictionary<string, List<string>> anagrams = new Dictionary<string, List<string>>();
            string[] words = File.ReadAllText(filename).Replace("\"", "").Split(',');
            foreach (string name in words)
            {
                string key = new String(name.ToCharArray().OrderBy(i => i).ToArray());

                if (!anagrams.ContainsKey(key))
                {
                    anagrams.Add(key, new List<string>());
                }

                anagrams[key].Add(name);
            }

            foreach (KeyValuePair<string, List<string>> anagram in anagrams)
            {
                if (anagram.Value.Count <= 1) continue;

                for (int i = 0; i < anagram.Value.Count; i++)
                {
                    for (int j = i + 1; j < anagram.Value.Count; j++)
                    {
                        int pairvalue = SquareAnagram(anagram.Value[i], anagram.Value[j]);
                        if (pairvalue > result)
                        {
                            result = pairvalue;
                        }
                        //Console.WriteLine("{0} and {1} are anagrams and gives {2}", anagram.Value[i], anagram.Value[j], pairvalue);
                    }
                }
            }

            clock.Stop();
            Console.WriteLine("The largest square number is {0}", result);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        private int SquareAnagram(string word1, string word2)
        {
            int max = 0;
            char[] w1array = word1.ToCharArray();
            char[] w2array = word2.ToCharArray();

            for (int i = 0; i < squares.Length; i++)
            {
                int squareLength = squares[i].ToString().Length;

                //Too short, keep looking
                if (squareLength < word1.Length)
                    continue;

                //Too int, stop search
                if (squareLength > word1.Length)
                    break;

                bool match = true;

                int square = squares[i];
                Dictionary<char, int> map = new Dictionary<char, int>();

                //Make a map out of the first word
                for (int j = w1array.Length - 1; j >= 0; j--)
                {
                    int digit = square % 10;
                    square /= 10;

                    //A repeated letter is found which doesn't match the square pattern
                    if (map.ContainsKey(w1array[j]))
                    {
                        if (map[w1array[j]] == digit)
                        {
                            continue;
                        }
                        else
                        {
                            match = false;
                            break;
                        }
                    }

                    //The value is already used
                    if (map.ContainsValue(digit))
                    {
                        match = false;
                        break;
                    }

                    map.Add(w1array[j], digit);
                }

                if (!match) continue;

                //Check if the map can be used for word 2
                int w2value = 0;
                if (map[w2array[0]] == 0)
                {
                    match = false;
                }
                else
                {
                    for (int j = 0; j < w2array.Length; j++)
                    {
                        w2value = w2value * 10 + map[w2array[j]];
                    }
                }

                if (!match) continue;
                if (Array.BinarySearch(squares, w2value) > -1)
                {
                    int maxpair = Math.Max(w2value, squares[i]);
                    max = Math.Max(max, maxpair);
                }
            }
            return max;
        }
    }
}
