import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws Exception {
        long ans = 0;
        BigInteger[] p = new BigInteger[8];
        p[0] = BigInteger.valueOf(19);
        p[1] = BigInteger.valueOf(29);
        p[2] = BigInteger.valueOf(39);
        p[3] = BigInteger.valueOf(49);
        p[4] = BigInteger.valueOf(59);
        p[5] = BigInteger.valueOf(69);
        p[6] = BigInteger.valueOf(79);
        p[7] = BigInteger.valueOf(89);
        BigInteger v = BigInteger.valueOf(99);
        BigInteger comp = BigInteger.TEN;
        BigInteger MOD = BigInteger.valueOf(100000);
        for (int i = 1; i < 100; ++i) {
            for (int b = 2; b <= 9; ++b) {
                BigInteger vv = v.multiply(BigInteger.valueOf(b));
                for (BigInteger d : p) {
                    if (vv.mod(d).signum() == 0) {
                        BigInteger n = vv.divide(d);
                        if (n.compareTo(comp) >= 0) {
                            ans += n.remainder(MOD).longValue();
                        }
                    }
                }
            }
            v = v.multiply(BigInteger.TEN).add(BigInteger.valueOf(9));
            comp = comp.multiply(BigInteger.TEN);
        }
        System.out.println(ans);
        ans += 11l * 45 + 111l * 45 + 1111l * 45 + 11111l * 45 * 96;
        System.out.println(ans);

        //        for (int i = 10; i <= 1000000; ++i) {
        //            if (i % 10 == 0) continue;
        //            int r = rev(i);
        //            if (r % i == 0) {
        //                System.out.println(i + " " + r / i);
        //            }
        //        }
    }

    static int rev(int v) {
        int ret = v / 10;
        int add = v % 10;
        while (v >= 10) {
            v /= 10;
            add *= 10;
        }
        return ret + add;
    }
}
