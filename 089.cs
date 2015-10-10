using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading;
using System.IO;
using System.Text.RegularExpressions;

namespace PE
{
    class Program
    {
        static void Main(string[] args)
        {
            string roman = File.ReadAllText("089-data.txt");
            string pattern = "DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII";
            string replacement = "kk";
            int result = roman.Length - Regex.Replace(roman, pattern, replacement).Length;
            Console.Write(result);
            Console.WriteLine();
        }
    }
}
