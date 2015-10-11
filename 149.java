public class Main {

    public static void main(String[] args) throws Exception {
        int[] table = new int[2000 * 2000];
        for (int i = 0; i < 55; ++i) {
            int k = i + 1;
            table[i] = (int) ((100003l - 200003l * k + 300007l * k * k * k) % 1000000 - 500000);
        }
        for (int i = 55; i < 2000 * 2000; ++i) {
            table[i] = (table[i - 24] + table[i - 55] + 1000000) % 1000000 - 500000;
        }
        long ans = Long.MIN_VALUE;
        long[] max = new long[2000];
        for (int i = 0; i < 2000; ++i) {
            max[0] = table[i * 2000];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j < 2000; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[i * 2000 + j];
                ans = Math.max(ans, max[j]);
            }
        }
        for (int i = 0; i < 2000; ++i) {
            max[0] = table[i];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j < 2000; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[j * 2000 + i];
                ans = Math.max(ans, max[j]);
            }
        }
        for (int i = 0; i < 2000; ++i) {
            max[0] = table[i * 2000];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j < 2000 - i; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[(i + j) * 2000 + j];
                ans = Math.max(ans, max[j]);
            }
            max[0] = table[i];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j < 2000 - i; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[j * 2000 + (i + j)];
                ans = Math.max(ans, max[j]);
            }
        }
        for (int i = 0; i < 2000; ++i) {
            max[0] = table[(i + 1) * 2000 - 1];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j < 2000 - i; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[(i + j) * 2000 + (1999 - j)];
                ans = Math.max(ans, max[j]);
            }
            max[0] = table[i];
            ans = Math.max(ans, max[0]);
            for (int j = 1; j <= i; ++j) {
                max[j] = Math.max(max[j - 1], 0) + table[j * 2000 + i - j];
                ans = Math.max(ans, max[j]);
            }
        }

        System.out.println(ans);
    }
}
