import java.util.ArrayList;
import java.util.HashMap;

public class Main {

    static long[][] memo1 = new long[8][(int) (Math.pow(3, 8))];
    static long[][] memo2 = new long[8][(int) (Math.pow(3, 8))];

    public static void main(String[] args) throws Exception {
        System.out.println(rec1(1, 1) * 6);
    }

    static long rec1(int r, int s) {
        if (memo1[r][s] > 0) {
            return memo1[r][s];
        }
        return memo1[r][s] = rec12(r, 0, s, 0);
    }

    static long rec12(int r, int c, int s, int cur) {
        if (c == r + 1) {
            if (r == 7) return 1;
            return rec2(r + 1, cur);
        }
        long ret = 0;
        int p1 = c == 0 ? -1 : s / (int) (Math.pow(3, r - c)) % 3;
        int p2 = c == r ? -1 : s / (int) (Math.pow(3, r - c - 1)) % 3;
        for (int i = 0; i < 3; ++i) {
            if (i != p1 && i != p2) {
                ret += rec12(r, c + 1, s, cur * 3 + i);
            }
        }
        return ret;
    }

    static long rec2(int r, int s) {
        if (memo2[r][s] > 0) {
            return memo2[r][s];
        }
        return memo2[r][s] = rec22(r, 0, s, 0);
    }

    static long rec22(int r, int c, int s, int cur) {
        if (c == r) {
            return rec1(r, cur);
        }
        long ret = 0;
        int p = s / (int) (Math.pow(3, r - c - 1)) % 3;
        for (int i = 0; i < 3; ++i) {
            if (i != p) {
                ret += rec22(r, c + 1, s, cur * 3 + i);
            }
        }
        return ret;
    }

}
