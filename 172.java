public class Main {

    public static void main(String[] args) throws Exception {
        long[] dp = new long[1 << 20];
        for (int i = 1; i <= 9; ++i) {
            dp[1 << (i * 2)] = 1;
        }
        for (int i = 0; i < 17; ++i) {
            long[] next = new long[1 << 20];
            for (int j = 0; j < (1 << 20); ++j) {
                if (dp[j] == 0) continue;
                for (int k = 0; k <= 9; ++k) {
                    int e = (j >> (k * 2)) & 3;
                    if (e == 3) continue;
                    next[j + (1 << (k * 2))] += dp[j];
                }
            }
            dp = next;
        }
        long ans = 0;
        for (int i = 0; i < (1 << 20); ++i) {
            ans += dp[i];
        }
        System.out.println(ans);
    }
}
