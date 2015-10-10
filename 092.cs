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
        private static int nextNumber(int input)
        {
            int retVal = 0;

            while (input > 0)
            {
                int digit = input % 10;
                retVal += digit * digit;
                input /= 10;
            }

            return retVal;
        }

        static void Main(string[] args)
        {
            int result = 0;
            int target = 10000000;
            int cachesize = (int)Math.Ceiling(81 * Math.Log10(target)) + 1;
            bool[] cache = new bool[cachesize + 1];

            for (int i = 1; i < cachesize; i++)
            {
                int sequence = nextNumber(i);

                while (sequence > i && sequence != 89)
                {
                    sequence = nextNumber(sequence);
                }

                if (cache[sequence] || sequence == 89)
                {
                    result++;
                    cache[i] = true;
                }
            }

            for (int i = cachesize; i <= target; i++)
            {
                if (cache[nextNumber(i)])
                {
                    result++;
                }
            }

            Console.Write(result);
            Console.WriteLine();
        }
    }
}
