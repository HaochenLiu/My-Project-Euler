#include <algorithm>
#include <iostream>
#include <stdio.h>

#define DIGIT_RANGE (10)

long long GCD(long long a, long long b) 
{
    while (b) 
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int number[DIGIT_RANGE] = {};

void DebugNumber()
{
    for (int i = 0; i < DIGIT_RANGE; i++)
    {
        printf("%d", number[i]);
    }
    putchar('\n');
}

inline long long BuildNumber(int start, int end)
{
    long long rv = 0;
    for (int i = start; i < end; i++)
    {
        rv *= 10;
        rv += number[i];
    }
    return rv;
}

bool IsPandigital(long long *numbers, int size)
{
    int used[10] = {};
    long long t;
    for (int i = 0; i < size; i++)
    {
        t = numbers[i];
        if (t == 0)
        {
            used[0]++;
        }
        while (t)
        {
            used[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 10 - DIGIT_RANGE; i < 10; i++)
    {
        if (used[i] != 1)
        {
            return false;
        }
    }
    return true;
}

long long N[15] = {};
long long M[15] = {};

bool IsConcatenated(int* pos_array, int size)
{
    N[0] = BuildNumber(0, pos_array[0]);
    for (int i = 1; i < size; i++)
    {
        N[i] = BuildNumber(pos_array[i-1], pos_array[i]);
    }
    N[size] = BuildNumber(pos_array[size-1], DIGIT_RANGE);

    long long gcd = GCD(N[0], N[1]);
    for (int i = 2; i <= size; i++)
    {
        gcd = GCD(gcd, N[i]);
    }
    for (int d = 1; d * d <= gcd; d++)
    {
        if (gcd % d)
        {
            continue;
        }

        M[0] = d;
        for (int i = 1; i <= size + 1; i++)
        {
            M[i] = N[i-1]/M[0];
        }
        if (IsPandigital(M, size + 2))
        {
            std::cout << BuildNumber(0, DIGIT_RANGE) << " => ";
            for (int i = 0; i <= size+1; i++)
            {
                std::cout << M[i] << " ";
            }
            std::cout << std::endl;
            return true;
        }

        M[0] = gcd/d;
        for (int i = 1; i <= size + 1; i++)
        {
            M[i] = N[i-1]/M[0];
        }
        if (IsPandigital(M, size + 2))
        {
            printf("%lld is concatenated product of %lld and (", 
                BuildNumber(0, DIGIT_RANGE), M[0]);
            for (int i = 1; i <= size+1; i++)
            {
                printf("%lld", M[i]);
                if (i != size + 1)
                {
                    putchar(',');
                }
            }
            printf(")\n");
            return true;
        }
    }
    return false;
}

bool IsConcatenated()
{
    int pos_array[15] = {};
    for (int i = 1; i < DIGIT_RANGE; i++)
    {
        pos_array[0] = i;
        if (IsConcatenated(pos_array, 1))
        {
            return true;
        }
        for (int j = i+1; j < DIGIT_RANGE; j++)
        {
            pos_array[1] = j;
            if (IsConcatenated(pos_array, 2))
            {
                return true;
            }
            for (int k = j+1; k < DIGIT_RANGE; k++)
            {
                pos_array[2] = k;
                if (IsConcatenated(pos_array, 3))
                {
                    return true;
                }
                for (int p = k+1; p < DIGIT_RANGE; p++)
                {
                    pos_array[3] = p;
                    if (IsConcatenated(pos_array, 4))
                    {
                        return true;
                    }
                    for (int q = p+1; q < DIGIT_RANGE; q++)
                    {
                        pos_array[4] = q;
                        if (IsConcatenated(pos_array, 5))
                        {
                            return true;
                        }
                        for (int r = q+1; r < DIGIT_RANGE; r++)
                        {
                            pos_array[5] = r;
                            if (IsConcatenated(pos_array, 6))
                            {
                                return true;
                            }
                            for (int s = r+1; s < DIGIT_RANGE; s++)
                            {
                                pos_array[6] = s;
                                if (IsConcatenated(pos_array, 7))
                                {
                                    return true;
                                }
                                for (int t = s+1; t < DIGIT_RANGE; t++)
                                {
                                    pos_array[7] = t;
                                    if (IsConcatenated(pos_array, 8))
                                    {
                                        return true;
                                    }
                                    for (int u = t+1; u < DIGIT_RANGE; u++)
                                    {
                                        pos_array[8] = u;
                                        if (IsConcatenated(pos_array, 9))
                                        {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

void Solve()
{
    for (int i = 0; i < DIGIT_RANGE; i++)
    {
        number[i] = 9 - i;
    }
    do 
    {
        if (IsConcatenated())
        {
            break;
        }
    }
    while (std::prev_permutation(number, number + DIGIT_RANGE));
}

int main()
{
    Solve();
    return 0;
}
