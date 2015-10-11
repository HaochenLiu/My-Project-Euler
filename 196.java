import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;

public class Main {
    static List<Integer> primes;
    static int SIZE;

    public static void main(String[] args) throws Exception {
        SIZE = 7208785;
        primes = primes((int) Math.sqrt((long) (SIZE + 2) * (SIZE * 3) / 2));

        //        System.out.println(isPrime(5678027l * (5678027l + 1) / 2 - 1));
        //        System.out.println(isPrime(5678027l * (5678027l - 1) / 2 + 2));
        //        System.out.println(isPrime(7208785l * (7208785l + 1) / 2));
        //        System.out.println(isPrime(7208785l * (7208785l + 1) / 2 - 2));
        //        System.out.println(isPrime(7208785l * (7208785l - 1) / 2 + 1));

        boolean[] composite = new boolean[SIZE * 5];
        long base = (long) (SIZE - 3) * (SIZE - 2) / 2;
        long last = base + composite.length;
        for (int i = 0; i < primes.size(); ++i) {
            int p = primes.get(i);
            long start = base + (p - base % p);
            for (long cur = start; cur <= last; cur += p) {
                composite[(int) (cur - base - 1)] = true;
            }
        }
        System.out.println("sieve");
        long ans = 0;
        for (int i = 2; i < SIZE - 3; ++i) {
            if (composite[SIZE * 2 - 3 + i]) continue;
            if (trip(i + base + SIZE * 2 - 3 + 1, composite, base)) {
                ans += i + base + SIZE * 2 - 3 + 1;
            }
        }
        System.out.println(ans);

    }

    static boolean trip(long v, boolean[] composite, long base) {
        boolean u = !composite[(int) (v - SIZE + 1 - base - 1)];
        boolean dl = !composite[(int) (v + SIZE - 1 - base - 1)];
        boolean dr = !composite[(int) (v + SIZE + 1 - base - 1)];
        if (u && dl || dl && dr || dr && u) return true;
        if (u) {
            if (!composite[(int) (v - (SIZE - 1) - (SIZE - 1) - base - 1)]
                    || !composite[(int) (v - (SIZE - 1) - (SIZE - 3) - base - 1)]) {
                return true;
            }
        }
        if (dl) {
            if (!composite[(int) (v - base - 3)] || !composite[(int) (v + (SIZE - 1) + (SIZE + 1) - base - 1)]) {
                return true;
            }
        }
        if (dr) {
            if (!composite[(int) (v - base + 1)] || !composite[(int) (v + (SIZE + 1) + (SIZE + 1) - base - 1)]) {
                return true;
            }
        }
        return false;
    }

    static boolean isPrime(long v) {
        int max = (int) Math.sqrt(v);
        for (int i = 0; i < primes.size() && primes.get(i) <= max; ++i) {
            if (v % primes.get(i) == 0) {
                //                System.out.println(primes.get(i));
                return false;
            }
        }
        return true;
    }

    public static List<Integer> primes(int max) {
        if (max < 2) {
            return new ArrayList<Integer>();
        }
        BitSet primeSet = new BitSet(max / 2);
        primeSet.set(1, max / 2);
        int limit = (int) Math.sqrt(max);
        for (int i = 3; i <= limit; i += 2) {
            if (!primeSet.get(i / 2)) {
                continue;
            }
            for (int j = i * i; j < max; j += i * 2) {
                primeSet.clear(j / 2);
            }
        }
        List<Integer> list = new ArrayList<Integer>();
        list.add(2);
        for (int i = primeSet.nextSetBit(0); i >= 0; i = primeSet.nextSetBit(i + 1)) {
            list.add(i * 2 + 1);
        }
        return list;
    }
}
