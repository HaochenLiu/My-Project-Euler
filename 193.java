import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;

public class Main {

    // 10000->6083

    static List<Integer> primes;
    static final long MAX = 1l << 50;
    static long count = 0;

    public static void main(String[] args) throws Exception {
        primes = primes((int) Math.sqrt(MAX));
        go(1, 0, 0);
        System.out.println(MAX - count);
    }

    static void go(long v, int index, int add) {
        for (int i = index; i < primes.size(); ++i) {
            long p = primes.get(i);
            if (v > MAX / p / p) break;
            long next = v * primes.get(i) * primes.get(i);
            if (next > MAX) return;
            count += MAX / next * (add % 2 == 0 ? 1 : -1);
            go(next, i + 1, add + 1);
        }
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
