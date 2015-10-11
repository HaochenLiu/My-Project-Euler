import java.util.ArrayList;
import java.util.HashMap;

public class Main {

    static int R = 9;
    static int C = 12;
    static boolean[][] f = new boolean[C + 2][R + 2];
    static ArrayList<HashMap<Integer, Long>> memo = new ArrayList<HashMap<Integer, Long>>();

    static int[][] dr = new int[][] { { 0, 1, 1 }, { 0, 0, -1 }, { 0, 0, 1 }, { 0, 0, 1 }, { 0, 1, 2 }, { 0, 0, 0 } };
    static int[][] dc = new int[][] { { 0, 0, 1 }, { 0, 1, 1 }, { 0, 1, 0 }, { 0, 1, 1 }, { 0, 0, 0 }, { 0, 1, 2 } };

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < R + 2; ++i) {
            f[0][i] = f[C + 1][i] = true;
        }
        for (int i = 0; i < C + 2; ++i) {
            f[i][0] = f[i][R + 1] = true;
        }
        for (int i = 0; i <= C; ++i) {
            memo.add(new HashMap<Integer, Long>());
        }
        System.out.println(rec(1, 1));
    }

    static long rec(int r, int c) {
        if (r == R+1) {
            if (c < C - 1) {
                int key = key(c + 1);
                if (memo.get(c).containsKey(key)) {
                    return memo.get(c).get(key);
                }
                long ret = rec(1, c + 1);
                memo.get(c).put(key, ret);
                return ret;
            } else if (c == C) {
                return 1;
            }
            return rec(1, c + 1);
        }
        if (f[c][r]) {
            return rec(r + 1, c);
        }
        long ret = 0;
        OUT: for (int i = 0; i < dr.length; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (f[c + dc[i][j]][r + dr[i][j]]) {
                    continue OUT;
                }
            }
            for (int j = 0; j < 3; ++j) {
                f[c + dc[i][j]][r + dr[i][j]] = true;
            }
            ret += rec(r + 1, c);
            for (int j = 0; j < 3; ++j) {
                f[c + dc[i][j]][r + dr[i][j]] = false;
            }
        }
        return ret;
    }

    static int key(int c) {
        int ret = 0;
        for (int i = 1; i <= R; ++i) {
            ret <<= 2;
            if (f[c][i]) ret += 1;
            if (f[c + 1][i]) ret += 2;
        }
        return ret;
    }
}
