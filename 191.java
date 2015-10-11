public class Main {

    public static void main(String[] args) throws Exception {
        long[][][] dp = new long[31][3][2];
        dp[0][0][0] = 1;
        for (int i = 1; i < dp.length; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 2; ++k) {
                    dp[i][0][k] += dp[i - 1][j][k];
                    if (j != 2) {
                        dp[i][j + 1][k] += dp[i - 1][j][k];
                    }
                }
                dp[i][0][1] += dp[i-1][j][0];
            }
        }
        long ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans += dp[dp.length - 1][i][j];
            }
        }
        System.out.println(ans);
    }

}
