import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {
        int[] cub = new int[37];
        cub[0] = 1;
        for (int i = 0; i < 6; ++i) {
            int[] next = new int[37];
            for (int j = 0; j < cub.length - 1; ++j) {
                if (cub[j] == 0) continue;
                for (int k = 1; k <= 6; ++k) {
                    next[j + k] += cub[j];
                }
            }
            cub = next;
        }
        int[] pyr = new int[37];
        pyr[0] = 1;
        for (int i = 0; i < 9; ++i) {
            int[] next = new int[37];
            for (int j = 0; j < pyr.length - 1; ++j) {
                if (pyr[j] == 0) continue;
                for (int k = 1; k <= 4; ++k) {
                    next[j + k] += pyr[j];
                }
            }
            pyr = next;
        }
        int allCub = 0;
        for (int i = 0; i < cub.length; ++i) {
            allCub += cub[i];
        }
        int allPyr = 0;
        for (int i = 0; i < pyr.length; ++i) {
            allPyr += pyr[i];
        }
        double ans = 0;
        for (int i = 0; i <= 36; ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                count += cub[j];
            }
            ans += 1. * pyr[i] / allPyr * count / allCub;
        }
        System.out.println(ans);
    }
}
