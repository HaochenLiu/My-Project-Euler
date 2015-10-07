using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PE
{
    class Program
    {
        private static bool IsPrime() 
        {
            string largeNumber = "300000000000000000000000000000000000000000000000000000000000000000000000000000000001";
            BigInteger bigInteger = BigInteger.Parse(largeNumber);
            if (bigInteger.IsEven) 
            {
                return false;
            }

            for (BigInteger bi = 3; BigInteger.Pow(bi, 2) <= bigInteger; bi += 2) 
            {
                if (bigInteger % bi == 0) 
                {
                    return false;
                }
            }

            return true;
        }

        static void Main(string[] args) 
        {
            if (IsPrime())
            {
                Console.Write("Prime");
            }
            else
            {
                Console.Write("Not prime");
            }
            Console.WriteLine();
        }
    }
}
