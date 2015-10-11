import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;

public class Main {

    static List<Integer> primes = primes(40000000);
    static int[] len = new int[40000001];
    static int[] totient = new int[40000001];

    public static void main(String[] args) throws Exception {
        len[1] = 1;
        totient[1] = 1;
        long ans = 0;
        System.out.println(primes.size());
        for (int p : primes) {
            long pp = p;
            while (pp < 40000000) {
                totient[(int) pp] = (int) (pp - pp / p);
                pp *= p;
            }
        }
        for (int p : primes) {
            if (length(p - 1) == 24) {
                System.out.println(p);
                ans += p;
            }
        }
        System.out.println(ans);
    }

    static int length(int v) {
        if (len[v] != 0) return len[v];
        int l = length(totient(v)) + 1;
        len[v] = l;
        //        System.out.println(v + " " + l);
        return l;
    }

    static int totient(int v) {
        if (totient[v] != 0) return totient[v];
        int ov = v;
        for (int i = 0; i < primes.size(); ++i) {
            int p = primes.get(i);
            if (v % p == 0) {
                int div = p;
                v /= p;
                int count = 1;
                while (v % p == 0) {
                    v /= p;
                    div *= p;
                    ++count;
                }
                int t = totient(v) * totient(div);
                totient[ov] = t;
                //                System.out.println(ov + " " + t);
                return t;
            }
        }
        return v - 1;
        //
        //        if (v % 4 == 0) {
        //            return totient(v / 2) * 2;
        //        }
        //        if (v % 9 == 0) {
        //            return totient(v / 3) * 3;
        //        }
        //        BitSet bs = new BitSet(v + 1);
        //        int sup = (int) Math.sqrt(v);
        //        for (int i = 0; primes.get(i) <= sup; ++i) {
        //            int p = primes.get(i);
        //            if (v % p != 0) continue;
        //            for (int j = p; j < v; j += p) {
        //                bs.set(j);
        //            }
        //        }
        //        return v - bs.cardinality() - 1;
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
