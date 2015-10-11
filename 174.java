public class Main {

    public static void main(String[] args) throws Exception {
        int[] c = new int[1000000 + 1];
        for (long i = 3; i < 1000000; ++i) {
            long ii = i * i;
            int count = 0;
            for (long j = i - 2; j > 0; j -= 2) {
                long t = ii - j * j;
                if (t > 1000000) break;
                c[(int) t]++;
            }
        }
        int ans = 0;
        for (int i : c) {
            if (1 <= i && i <= 10) {
                ++ans;
            }
        }
        System.out.println(ans);
    }
}
