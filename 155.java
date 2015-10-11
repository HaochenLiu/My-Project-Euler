import java.util.ArrayList;
import java.util.HashSet;

public class Main {

    public static void main(String[] args) throws Exception {
        ArrayList<HashSet<Rational>> sets = new ArrayList<HashSet<Rational>>();
        for (int i = 0; i <= 18; ++i) {
            sets.add(new HashSet<Rational>());
        }
        sets.get(1).add(new Rational(1));
        for (int i = 2; i <= 18; ++i) {
            HashSet<Rational> set = sets.get(i);
            for (int j = 1; j <= i / 2; ++j) {
                for (Rational r1 : sets.get(j)) {
                    for (Rational r2 : sets.get(i - j)) {
                        set.add(r1.add(r2));
                        set.add(r1.revadd(r2));
                    }
                }
            }
            System.out.println(set.size());
        }
        HashSet<Rational> all = sets.get(18);
        for (int i = 17; i >= 1; --i) {
            all.addAll(sets.get(i));
        }
        System.out.println(all.size());
    }
}

class Rational {
    final long num;
    final long den;

    Rational(long num) {
        this.num = num;
        this.den = 1;
    }

    Rational(long num, long den) {
        long gcd = gcd(num, den);
        this.num = num / gcd;
        this.den = den / gcd;
    }

    Rational add(Rational o) {
        long lcm = lcm(this.den, o.den);
        return new Rational(this.num * (lcm / this.den) + o.num * (lcm / o.den), lcm);
    }

    Rational revadd(Rational o) {
        long lcm = lcm(this.num, o.num);
        return new Rational(lcm, this.den * (lcm / this.num) + o.den * (lcm / o.num));
    }

    public int hashCode() {
        final int prime = 31;
        long result = 1;
        result = prime * result + den;
        result = prime * result + num;
        return (int) result;
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null) return false;
        if (getClass() != obj.getClass()) return false;
        Rational other = (Rational) obj;
        if (den != other.den) return false;
        if (num != other.num) return false;
        return true;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}
