import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws Exception {
        int ans = 0;
        for (int i = 5; i <= 10000; ++i) {
            int k = max(i);
            ans += inf(i, k) ? i : -i;
        }
        System.out.println(ans);
    }

    static int max(int v) {
        int d = (int) (v / Math.E);
        BigInteger v1 = BigInteger.valueOf(d + 1).pow(d + 1);
        BigInteger v2 = BigInteger.valueOf(d).pow(d).multiply(BigInteger.valueOf(v));
        return v1.compareTo(v2) > 0 ? d : d + 1;
    }

    static boolean inf(int n, int d) {
        int gcd = gcd(n, d);
        int dd = d / gcd;
        while (dd % 2 == 0) {
            dd /= 2;
        }
        while (dd % 5 == 0) {
            dd /= 5;
        }
        return dd != 1;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
