public class Main {

    public static void main(String[] args) throws Exception {
        long ans = calc(1777, 1855, 100000000);
        System.out.println(ans);
    }

    static long calc(long base, int pow, long mod) {
        if (pow == 1) {
            return base;
        }
        int nextMod = 1;
        long v = base;
        while (v != 1) {
            v *= base;
            v %= mod;
            ++nextMod;
        }
        System.out.println("pow:" + pow + " mod:" + nextMod);
        long rp = calc(base, pow - 1, nextMod);
        long ret = 1;
        for (int i = 0; i < rp; ++i) {
            ret *= base;
            ret %= mod;
        }
        System.out.println("pow:" + pow + " ret:" + ret);
        return ret;
    }
}
