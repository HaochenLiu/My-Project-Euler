import java.util.HashSet;

public class Main {

    public static void main(String[] args) throws Exception {
        int[] primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47 };
        HashSet<Long> set = new HashSet<Long>();
        long[] pascal = new long[51];
        pascal[0] = pascal[1] = 1;
        for (int i = 2; i <= 50; ++i) {
            long[] next = new long[51];
            for (int j = 1; j < i; ++j) {
                long v = pascal[j - 1] + pascal[j];
                set.add(v);
                next[j] = v;
            }
            next[0] = next[i] = 1;
            pascal = next;
        }
        long ans = 0;
        for (long l : set) {
            boolean free = true;
            for (int p : primes) {
                if (l % (p * p) == 0) {
                    free = false;
                    break;
                }
            }
            if (free) {
                ans += l;
            }
        }
        System.out.println(ans);
    }
}
