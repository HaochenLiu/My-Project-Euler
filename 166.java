public class Main {

    static int sum;
    static int[][] matrix = new int[4][4];
    static int ans = 0;

    public static void main(String[] args) throws Exception {
        for (int i1 = 0; i1 <= 9; ++i1) {
            matrix[0][0] = i1;
            for (int i2 = 0; i2 <= 9; ++i2) {
                matrix[0][1] = i2;
                for (int i3 = 0; i3 <= 9; ++i3) {
                    matrix[0][2] = i3;
                    for (int i4 = 0; i4 <= 9; ++i4) {
                        matrix[0][3] = i4;
                        sum = i1 + i2 + i3 + i4;
                        solve();
                    }
                }
            }
        }
        System.out.println(ans);
    }

    static void solve() {
        int rest = sum - matrix[0][0];
        for (int i = Math.max(0, rest - 18); i <= Math.min(9, rest); ++i) {
            int rest2 = rest - i;
            matrix[1][0] = i;
            for (int j = Math.max(0, rest2 - 9); j <= Math.min(9, rest2); ++j) {
                matrix[2][0] = j;
                matrix[3][0] = rest2 - j;
                solve2();
            }
        }
    }

    static void solve2() {
        int rest = sum - matrix[0][3] - matrix[3][0];
        for (int i = Math.max(0, rest - 9); i <= Math.min(9, rest); ++i) {
            matrix[2][1] = i;
            matrix[1][2] = rest - i;
            int restR = sum - matrix[1][0] - matrix[1][2];
            int restC = sum - matrix[0][1] - matrix[2][1];
            int min = Math.max(0, Math.max(restR - 9, restC - 9));
            int max = Math.min(9, Math.min(restR, restC));
            for (int j = min; j <= max; ++j) {
                matrix[1][1] = j;
                matrix[1][3] = restR - j;
                matrix[3][1] = restC - j;
                solve3();
            }
        }
    }

    static void solve3() {
        int restR = sum - matrix[2][0] - matrix[2][1];
        int restC = sum - matrix[0][2] - matrix[1][2];
        int min = Math.max(0, Math.max(restR - 9, restC - 9));
        int max = Math.min(9, Math.min(restR, restC));
        for (int j = min; j <= max; ++j) {
            matrix[2][2] = j;
            matrix[2][3] = restR - j;
            matrix[3][2] = restC - j;
            int last = sum - matrix[0][3] - matrix[1][3] - matrix[2][3];
            if (0 <= last && last <= 9 && matrix[0][0] + matrix[1][1] + matrix[2][2] + last == sum
                    && matrix[3][0] + matrix[3][1] + matrix[3][2] + last == sum) {
                ++ans;
            }
        }
    }
}
