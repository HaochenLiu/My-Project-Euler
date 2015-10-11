import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.List;

public class Main {

    static List<Integer> primes = primes(100000);

    public static void main(String[] args) throws Exception {
        long ans = 0;
        for (int i = 1; i <= 9; ++i) {
            ans += solve(i);
            System.out.println(ans);
        }
        System.out.println(ans);
    }

    static long solve(int n) {
        long ret = 0;

        // 1,1
        ret += (n + 2) * (n + 1);

        // 1, 2^i
        for (int i = 1; i <= n; ++i) {
            long num = 1 + pow(2, i);
            HashMap<Long, Integer> factor = factorize(num);
            factor.put(2l, n - i);
            if (factor.containsKey(5l)) {
                factor.put(5l, factor.get(5l) + n);
            } else {
                factor.put(5l, n);
            }
            ret += count(factor);
        }

        // 1, 5^i
        for (int i = 1; i <= n; ++i) {
            long num = 1 + pow(5, i);
            HashMap<Long, Integer> factor = factorize(num);
            factor.put(5l, n - i);
            if (factor.containsKey(2l)) {
                factor.put(2l, factor.get(2l) + n);
            } else {
                factor.put(2l, n);
            }
            ret += count(factor);
        }

        // 2^i, 5^j
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                long num = pow(2, i) + pow(5, j);
                HashMap<Long, Integer> factor = factorize(num);
                if (factor.containsKey(2l)) {
                    factor.put(2l, factor.get(2l) + n - i);
                } else {
                    factor.put(2l, n - i);
                }
                if (factor.containsKey(5l)) {
                    factor.put(5l, factor.get(5l) + n - j);
                } else {
                    factor.put(5l, n - j);
                }
                ret += count(factor);
            }
        }

        // 1, 2^i*5^j
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                long num = pow(2, i) * pow(5, j) + 1;
                HashMap<Long, Integer> factor = factorize(num);
                factor.put(2l, n - i);
                factor.put(5l, n - j);
                ret += count(factor);
            }
        }
        return ret;
    }

    static long count(HashMap<Long, Integer> factor) {
        long ret = 1l;
        for (int f : factor.values()) {
            ret *= (f + 1);
        }
        return ret;
    }

    static HashMap<Long, Integer> factorize(long v) {
        HashMap<Long, Integer> ret = new HashMap<Long, Integer>();
        for (int j = 0; j < primes.size() && v > 1; ++j) {
            int p = primes.get(j);
            int c = 0;
            while (v % p == 0) {
                ++c;
                v /= p;
            }
            if (c > 0) {
                ret.put((long) p, c);
            }
        }
        if (v > 1) {
            ret.put(v, 1);
        }
        return ret;
    }

    static long pow(int b, int p) {
        long ret = 1;
        for (int i = 0; i < p; ++i) {
            ret *= b;
        }
        return ret;
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
