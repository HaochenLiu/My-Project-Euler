public class Main {

    public static void main(String[] args) throws Exception {
        long[][] s = new long[1000][1000];
        long t = 0;
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j <= i; ++j) {
                t = (615949 * t + 797807) % (1 << 20);
                s[i][j] = t - (1 << 19);
            }
        }
        long ans = Long.MAX_VALUE;
        long[][] prev = null;
        long[][] cur = new long[1001][1];
        for (int i = 999; i >= 0; --i) {
            long[][] next = new long[i + 1][1001 - i];
            for (int j = 0; j <= i; ++j) {
                next[j][1] = s[i][j];
                ans = Math.min(ans, next[j][1]);
                for (int k = 2; k < 1001 - i; ++k) {
                    next[j][k] = s[i][j] + cur[j][k - 1] + cur[j + 1][k - 1] - prev[j + 1][k - 2];
                    ans = Math.min(ans, next[j][k]);
                }
            }
            prev = cur;
            cur = next;
        }
        System.out.println(ans);
    }

}
