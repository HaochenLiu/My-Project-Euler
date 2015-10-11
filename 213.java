public class Main {

    static int[] dr = new int[] { 0, 1, 0, -1 };
    static int[] dc = new int[] { 1, 0, -1, 0 };

    public static void main(String[] args) throws Exception {
        double[][][][] p = new double[30][30][30][30];
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                double[][][] map = new double[51][30][30];
                map[0][i][j] = 1;
                for (int t = 0; t < 50; ++t) {
                    for (int r = 0; r < 30; ++r) {
                        for (int c = 0; c < 30; ++c) {
                            int count = 4;
                            if (r == 0 || r == 29 || c == 0 || c == 29) count = 3;
                            if (r == 0 && c == 0 || r == 0 && c == 29 || r == 29 && c == 0 || r == 29 && c == 29) count = 2;
                            for (int k = 0; k < 4; ++k) {
                                int nr = r + dr[k];
                                int nc = c + dc[k];
                                if (nr == -1 || nr == 30 || nc == -1 || nc == 30) continue;
                                map[t + 1][nc][nr] += map[t][c][r] / count;
                            }
                        }
                    }
                }
                p[i][j] = map[50];
            }
        }
        double ans = 0;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                double empty = 1.0;
                for (int r = 0; r < 30; ++r) {
                    for (int c = 0; c < 30; ++c) {
                        empty *= (1 - p[c][r][i][j]);
                    }
                }
                ans += empty;
            }
        }
        System.out.println(ans);
    }
}
