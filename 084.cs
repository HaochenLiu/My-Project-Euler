using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace PE
{
    class Program
    {
        static Random random;
        static int cPos = 0;
        static int ccPos = 0;
        static int chancePos = 0;
        private static void CC()
        {
            int[] cc = { 0, 10 };
            ccPos = ++ccPos % 16;

            if (ccPos < 2)
            {
                cPos = cc[ccPos];
            }
            return;
        }

        private static void chance()
        {
            int[] chance = { 0, 10, 11, 24, 39, 5 };

            chancePos = ++chancePos % 16;

            if (chancePos < 6)
            {
                cPos = chance[chancePos];
            }

            if (chancePos == 6 || chancePos == 7)
            {
                if (cPos == 7) cPos = 15;
                if (cPos == 22) cPos = 25;
                if (cPos == 36) cPos = 5;
            }

            if (chancePos == 8)
            {
                cPos = (cPos == 22) ? 28 : 12;
            }

            if (chancePos == 9) cPos -= 3;
            return;
        }

        static void Main(string[] args)
        {
            int[] board = new int[40];
            int samples = 1000000;
            random = new Random();
            int doubles = 0;

            for (int i = 0; i < samples; i++)
            {
                //roll the dices
                int dice1 = random.Next(4) + 1;
                int dice2 = random.Next(4) + 1;

                //Check doubles
                doubles = (dice1 == dice2) ? doubles + 1 : 0;

                if (doubles > 2)
                {
                    cPos = 10;
                    doubles = 0;
                }
                else
                {
                    //Move to the square
                    cPos = (cPos + dice1 + dice2) % 40;

                    //Handle chance
                    //Important first, as you can go CH3->CC3
                    if (cPos == 7 || cPos == 22 || cPos == 36) chance();
                    //Handle CH
                    if (cPos == 2 || cPos == 17 || cPos == 33) CC();
                    //Handle G2J
                    if (cPos == 30) cPos = 10;
                }
                board[cPos]++;
            }
            int[] index = board
                          .Select((item, indx) => new { Item = item, Index = indx })
                          .OrderByDescending(x => x.Item)
                          .Select(x => x.Index)
                          .ToArray();

            string modalstring = "";
            for (int i = 0; i < 3; i++)
            {
                if (index[i] < 10) modalstring += "0";
                modalstring += index[i].ToString();
            }

            Console.Write(modalstring);
            Console.WriteLine();
        }
    }
}
