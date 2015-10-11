import java.util.HashMap;

public class Main {

    static int[] divs = new int[] { 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36, 40, 45, 48, 50, 60,
            64, 72, 75, 80 };
    static Rational[] ras;
    static HashMap<Rational, Integer> set = new HashMap<Rational, Integer>();
    static int ans = 0;

    public static void main(String[] args) throws Exception {
        ras = new Rational[divs.length];
        for (int i = 0; i < divs.length; ++i) {
            ras[i] = new Rational(1, divs[i] * divs[i]);
        }
        int base = 7;
        for (int i = 1; i < (1 << 10); ++i) {
            long prod = 1;
            for (int j = 0; j < 10; ++j) {
                if ((i & (1 << j)) != 0) {
                    prod *= (j + 1) * (j + 1);
                }
            }
            long sum = 0;
            for (int j = 0; j < 10; ++j) {
                if ((i & (1 << j)) != 0) {
                    sum += prod / (j + 1) / (j + 1);
                }
            }
            if (sum % (base * base) == 0) {
                //                System.out.print(Integer.toBinaryString(i));
                Rational r = new Rational(sum / base / base, prod);
                Rational ra = r.add(1, 144); // 13, 39, 52
                addToSet(r);
                addToSet(ra);
            }
        }
        addToSet(new Rational(1, 144));
        System.out.println(set);
        rec(new Rational(1, 4), 0);
        System.out.println(ans);
    }

    static void rec(Rational cur, int index) {
        if (index == ras.length) return;
        rec(cur, index + 1);
        if (cur.compareTo(ras[index]) >= 0) {
            if (cur.equals(ras[index])) {
                ans += 1;
                return;
            }
            Rational next = cur.subtract(ras[index]);
            if (set.containsKey(next)) {
                ans += set.get(next);
            }
            rec(next, index + 1);
            return;
        }

    }

    static void addToSet(Rational r) {
        if (set.containsKey(r)) {
            set.put(r, set.get(r) + 1);
        } else {
            set.put(r, 1);
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static class Rational {
        final long num;
        final long den;

        Rational(long n, long d) {
            if (n == 0) {
                num = 0;
                den = 1;
            } else {
                long gcd = gcd(Math.abs(n), Math.abs(d));
                num = n / gcd;
                den = d / gcd;
            }
        }

        Rational mul(long n, long d) {
            return new Rational(this.num * n, this.den * d);
        }

        Rational add(long n, long d) {
            return new Rational(this.num * d + n * this.den, this.den * d);
        }

        Rational add(Rational r) {
            return add(r.num, r.den);
        }

        Rational subtract(Rational r) {
            return add(-r.num, r.den);
        }

        public int compareTo(Rational r) {
            long n1 = this.num * r.den;
            long n2 = this.den * r.num;
            if (n1 > n2) {
                return 1;
            } else if (n1 == n2) {
                return 0;
            } else {
                return -1;
            }
        }

        public String toString() {
            return this.num + "/" + this.den;
        }

        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (int) (den ^ (den >>> 32));
            result = prime * result + (int) (num ^ (num >>> 32));
            return result;
        }

        public boolean equals(Object obj) {
            Rational other = (Rational) obj;
            if (den != other.den) return false;
            if (num != other.num) return false;
            return true;
        }
    }
}
