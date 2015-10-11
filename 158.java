public class Main {

    public static void main(String[] args) throws Exception {
        long[] base = new long[27];
        base[2] = 1;
        for (int i = 3; i <= 26; ++i) {
            base[i] = (1 << (i - 1)) - 1 + base[i - 1];
        }
        long ans = 0;
        for (int i = 2; i <= 26; ++i) {
            ans = Math.max(ans, comb(26, i) * base[i]);
        }
        System.out.println(ans);
    }

    static long comb(int n, int m) {
        long ans = 1;
        for (int i = 0; i < m; ++i) {
            ans *= (n - i);
            ans /= (i + 1);
        }
        return ans;
    }
}
