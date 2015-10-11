public class Main {

    public static void main(String[] args) throws Exception {
        int ans = 0;
        for (int r = 1; r <= 43; ++r) {
            for (int c = 1; c <= 47; ++c) {
                ans += count(r, c);
            }
        }
        System.out.println(ans);
    }

    static int count(int r, int c) {
        int ret = r * (r + 1) / 2 * c * (c + 1) / 2;
        int[] start = new int[r + c - 1];
        int[] end = new int[r + c - 1];
        for (int i = r - 1; i > 0; --i) {
            start[r - 1 - i] = i;
            end[r - 1 - i] = i + 2 * Math.min(r - i, c);
        }
        for (int i = 0; i < c; ++i) {
            start[r - 1 + i] = i;
            end[r - 1 + i] = i + 2 * Math.min(c - i, r);
        }
        for (int i = 0; i < start.length; ++i) {
            for (int j = i + 1; j < start.length; ++j) {
                int s = Math.max(start[i], start[j]);
                int e = Math.min(end[i], end[j]);
                if (s < e) {
                    ret += (e - s) * (e - s + 1) / 2;
                }
            }
        }
        return ret;
    }
}
