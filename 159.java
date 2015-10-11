public class Main {

    public static void main(String[] args) throws Exception {
        final int size = 1000000;
        int[] m = new int[size];
        long ans = 0;
        for (int i = 2; i < size; ++i) {
            int max = root(i);
            int sup = (int) Math.sqrt(i);
            for (int j = 2; j <= sup; ++j) {
                if (i % j == 0) {
                    max = Math.max(max, m[j] + m[i / j]);
                }
            }
            m[i] = max;
            ans += max;
        }
        System.out.println(ans);
    }

    static int root(int v) {
        int ret = 0;
        while (v > 0) {
            ret += v % 10;
            v /= 10;
        }
        return ret >= 10 ? root(ret) : ret;
    }
}
