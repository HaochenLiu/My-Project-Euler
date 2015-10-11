public class Main {

    public static void main(String[] args) throws Exception {
        long[][][][] dp = new long[40][10][10][10];
        for (int i = 1; i <= 9; ++i) {
            dp[0][i][i][i] = 1;
        }
        for (int i = 0; i < 39; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int k = 0; k <= 9; ++k) {
                    for (int l = k; l <= 9; ++l) {
                        if (dp[i][j][k][l] == 0) continue;
                        if (j != 0) {
                            dp[i + 1][j - 1][Math.min(k, j - 1)][l] += dp[i][j][k][l];
                        }
                        if (j != 9) {
                            dp[i + 1][j + 1][k][Math.max(l, j + 1)] += dp[i][j][k][l];
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < 40; ++i) {
            for (int j = 0; j <= 9; ++j) {
                ans += dp[i][j][0][9];
            }
        }
        System.out.println(ans);
    }
}
