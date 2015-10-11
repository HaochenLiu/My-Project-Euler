import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {
        int[] next = new int[1 << 6];
        for (int i = 0; i < (1 << 6); ++i) {
            next[i] = (i % (1 << 5)) << 1;
            int a = i >> 5;
            int b = (i >> 4) & 1;
            int c = (i >> 3) & 1;
            next[i] += a ^ (b & c);
        }
        System.out.println(Arrays.toString(next));
        int[] group = new int[next.length];
        int[] gc = new int[10];
        int g = 1;
        for (int i = 0; i < group.length; ++i) {
            if (group[i] != 0) continue;
            group[i] = g;
            gc[g]++;
            for (int cur = next[i]; cur != i; cur = next[cur]) {
                group[cur] = g;
                gc[g]++;
            }
            ++g;
        }
        System.out.println(Arrays.toString(group));
        System.out.println(Arrays.toString(gc));
        long[] dp = new long[next.length];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < dp.length; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        System.out.println(Arrays.toString(dp));
        long ans = 1;
        for (int i = 2; i < g; ++i) {
            long mul = dp[gc[i] - 1];
            if (gc[i] >= 3) {
                mul += dp[gc[i] - 3];
            }
            if (gc[i] == 2) ++mul;
            ans *= mul;
        }
        System.out.println(ans);
    }
}
