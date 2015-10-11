public class Main {

    static long ans = 0;
    static final int size = 200000;
    static int[] div5 = new int[size + 1];
    static int[] div2 = new int[size + 1];

    public static void main(String[] args) throws Exception {
        for (int i = 1; i <= size; ++i) {
            div5[i] = div5(i);
            div2[i] = div2(i);
        }
        int all2 = div2[size];
        int all5 = div5[size];
        for (int i = size; i > size / 3; --i) {
            int i2 = div2[i];
            int i5 = div5[i];
            int jk = size - i;
            for (int j = (jk + 1) / 2; j <= jk && j <= i; ++j) {
                int k = jk - j;
                int j2 = div2[j];
                int k2 = div2[k];
                int j5 = div5[j];
                int k5 = div5[k];
                if (all5 - i5 - j5 - k5 >= 12 && all2 - i2 - j2 - k2 >= 12) {
                    ans += (i == j || j == k) ? 3 : 6;
                }
            }
        }
        System.out.println(ans);
    }

    static int div5(int v) {
        return v / 5 + div5[v / 5];
    }

    static int div2(int v) {
        return v / 2 + div2[v / 2];
    }
}
