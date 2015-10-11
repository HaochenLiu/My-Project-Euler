import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {
        final int SIZE = 100000000;
        List<Integer> primes = primes(SIZE / 2);
        int ans = 0;
        for (int i = 0; primes.get(i) <= (int) Math.sqrt(SIZE); ++i) {
            int pos = Collections.binarySearch(primes, SIZE / primes.get(i));
            if (pos < 0) {
                pos = -pos - 2;
            }
            ans += pos - i + 1;
        }
        System.out.println(ans);
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
