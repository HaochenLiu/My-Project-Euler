public class Main {

    public static void main(String[] args) throws Exception {
        long ans = 0;
        for (long i = 2; i < 1000000; ++i) {
            long ii = i * i;
            for (long j = i - 2; j > 0; j -= 2) {
                if (ii - j * j > 1000000) break;
                ++ans;
            }
        }
        System.out.println(ans);
    }
}
