using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading;

namespace PE
{
    class Program
    {
        static void Main(string[] args)
        {
            int maxK = 12000;
            int maxNumber = 2 * maxK;

            int numFactors = (int)(Math.Log10(maxNumber) / Math.Log10(2));
            int[] factors = new int[numFactors];

            int[] k = Enumerable.Range(0, maxK + 1).Select(x => x * 2).ToArray();
            k[1] = 0;

            factors[0] = 1;
            int curMaxFactor = 1;
            int j = 0;

            while (true)
            {
                if (j == 0)
                {
                    //at first factor
                    if (curMaxFactor == numFactors)
                        //Used all the factos we can
                        break;

                    if (factors[0] < factors[1])
                    {
                        //can increment
                        factors[0]++;
                    }
                    else
                    {
                        //add another factor
                        curMaxFactor++;
                        factors[curMaxFactor - 1] = int.MaxValue;
                        factors[0] = 2;
                    }

                    j++;
                    factors[1] = factors[0] - 1;
                }
                else if (j == curMaxFactor - 1)
                {
                    //At the max factor
                    factors[j]++;
                    int sum = 0;
                    int prod = 1;
                    for (int i = 0; i < curMaxFactor; i++)
                    {
                        prod *= factors[i];
                        sum += factors[i];
                    }

                    if (prod > maxNumber)
                    {
                        //Exceed the limit so go back
                        j--;
                    }
                    else
                    {
                        //Check the result
                        int pk = prod - sum + curMaxFactor;
                        if (pk <= maxK && prod < k[pk])
                        {
                            k[pk] = prod;
                        }
                    }
                }
                else if (factors[j] < factors[j + 1])
                {
                    //increment the reset the next factor
                    //and go up
                    factors[j]++;
                    factors[j + 1] = factors[j] - 1;
                    j++;
                }
                else if (factors[j] >= factors[j + 1])
                {
                    //Need to go further back
                    j--;
                }
            }
            int result = k.Distinct().Sum();

            Console.Write(result);
            Console.WriteLine();
        }
    }
}
