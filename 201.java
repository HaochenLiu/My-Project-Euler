public class Main {

    public static void main(String[] args) throws Exception {
        int all = 0;
        for (int i = 1; i <= 100; ++i) {
            all += i * i;
        }
        System.out.println(all);
        int[][] exist = new int[51][all + 1];
        exist[0][0] = 1;
        int sum = 0;
        for (int i = 1; i <= 100; ++i) {
            int[][] next = new int[51][all + 1];
            for (int j = 0; j < 50; ++j) {
                for (int k = 0; k <= sum; ++k) {
                    next[j][k] += exist[j][k];
                    next[j + 1][k + i * i] += exist[j][k];
                }
            }
            for (int k = 0; k <= sum; ++k) {
                next[50][k] += exist[50][k];
            }
            sum += i * i;
            exist = next;
        }
        int ans = 0;
        for (int i = 0; i <= all; ++i) {
            if (exist[50][i] == 1) {
                ans += i;
            }
        }
        System.out.println(ans);
    }
}
