#include <iostream>
#include <set>
#include <stdio.h>

inline long long Norm(long long a)
{
    return (a < 0) ? -a : a;
}

long long GCD(long long a, long long b) 
{
    a = Norm(a);
    b = Norm(b);
    while (b) 
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

// -----------------------------------------------------------------------------

struct Fraction
{
    long long n;
    long long d;

    Fraction(): n(0), d(1) { }
    Fraction(long long init_n): n(init_n), d(1) { }
    Fraction(long long init_n, long long init_d): n(init_n), d(init_d) 
    { 
        Normalize();
    }

    static Fraction Add(const Fraction& a, const Fraction& b)
    {
        return Fraction(a.n * b.d + b.n * a.d, a.d * b.d);
    }

    static Fraction Minus(const Fraction& a, const Fraction& b)
    {
        return Fraction(a.n * b.d - b.n * a.d, a.d * b.d);
    }
    
    static Fraction Multiply(const Fraction& a, const Fraction& b)
    {
        return Fraction(a.n * b.n, a.d * b.d);
    }

    static Fraction Divide(const Fraction& a, const Fraction& b)
    {
        return Fraction(a.n * b.d, a.d * b.n);
    }

    void Normalize()
    {
        long long gcd = GCD(n, d);
        if (gcd)
        {
            n /= gcd;
            d /= gcd;
        }
        if (d < 0)
        {
            n *= -1;
            d *= -1;
        }
    }

    bool operator < (const Fraction& other) const
    {
        return n * other.d < other.n * d;
    }

    bool operator == (const Fraction& other) const
    {
        return n * other.d == other.n * d;
    }
};

// -----------------------------------------------------------------------------

struct Point 
{
    long long x;
    long long y;

    Point() : x(0), y(0) { }
    Point(long long new_x, long long new_y) : x(new_x), y(new_y) { }
};

struct FractionPoint
{
    Fraction x;
    Fraction y;

    bool operator < (const FractionPoint& other) const
    {
        if (x == other.x)
        {
            return y < other.y;
        }
        return x < other.x;
    }

    void Debug()
    {
        printf("Fraction Point: (%lld/%lld, %lld/%lld)\n", x.n, x.d, y.n, y.d);
    }
};

// -----------------------------------------------------------------------------

long long Direction(const Point& pi, const Point& pj, const Point& pk)
{
    Point pki(pk.x - pi.x, pk.y - pi.y);
    Point pji(pj.x - pi.x, pj.y - pi.y);
    return pki.x * pji.y - pji.x * pki.y;
}

bool SegmentsIntersect(
    const Point& p1, const Point& p2, 
    const Point& p3, const Point& p4)
{
    long long d1 = Direction(p3, p4, p1);
    long long d2 = Direction(p3, p4, p2);
    long long d3 = Direction(p1, p2, p3);
    long long d4 = Direction(p1, p2, p4);

    return ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0));
}

FractionPoint GetIntersectionPoint(
    const Point& p1, const Point& p2, 
    const Point& p3, const Point& p4)
{
    Point q1(p2.x - p1.x, p2.y - p1.y);
    Point q2(p4.x - p3.x, p4.y - p3.y);
    Fraction t(
        q2.x * (p1.y - p3.y) - q2.y * (p1.x - p3.x), 
        q1.x * q2.y - q2.x * q1.y);

    FractionPoint point;
    point.x = Fraction::Add(Fraction(p1.x), Fraction::Multiply(t, q1.x));
    point.y = Fraction::Add(Fraction(p1.y), Fraction::Multiply(t, q1.y));
    return point;
}

// -----------------------------------------------------------------------------

Point L[5000][2];

void InitLineSegments()
{
    long long generator = 290797;
    for (int i = 0; i < 20000; i++)
    {
        generator = (generator * generator) % 50515093;
        if (i % 2 == 0)
        {
            L[i/4][(i%4)/2].x = generator % 500;
        }
        else
        {
            L[i/4][(i%4)/2].y = generator % 500;
        }
    }
}

std::set<FractionPoint> intersection_points;

void BuildIntersectionPoints()
{
    for (int i = 0; i < 5000; i++)
    {
        for (int j = i+1; j < 5000; j++)
        {
            if (SegmentsIntersect(L[i][0], L[i][1], L[j][0], L[j][1]))
            {
                FractionPoint p = GetIntersectionPoint(L[i][0], L[i][1], L[j][0], L[j][1]);
                intersection_points.insert(p);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitLineSegments();
    BuildIntersectionPoints();
    std::cout << intersection_points.size() << std::endl;
    return 0;
}
