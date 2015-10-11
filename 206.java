public class Main {

    public static void main(String[] args) throws Exception {
        for (long i = 100000000l;; ++i) {
            long v = i * i;
            if (ok(v)) {
                System.out.println(i);
                return;
            }
        }
    }

    static boolean ok(long v) {
        for (int i = 9; i >= 1; --i) {
            if (v % 10 != i) return false;
            v /= 100;
        }
        return true;
    }
}
