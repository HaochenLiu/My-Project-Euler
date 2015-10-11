public class Main {

    public static void main(String[] args) throws Exception {
        long[][][] dp = new long[21][10][10];
        for (int i = 1; i <= 9; ++i) {
            dp[1][0][i] = 1;
        }
        for (int i = 2; i <= 20; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int k = 0; k <= 9; ++k) {
                    for (int next = 0; j + k + next <= 9; ++next) {
                        dp[i][k][next] += dp[i-1][j][k];
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                ans += dp[20][i][j];
            }
        }
        System.out.println(ans);
    }
}
