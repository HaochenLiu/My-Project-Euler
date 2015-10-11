import java.math.BigInteger;
import java.util.HashMap;

public class Main {

    static HashMap<BigInteger, Long> memo = new HashMap<BigInteger, Long>();
    static final BigInteger TWO = BigInteger.valueOf(2);

    public static void main(String[] args) throws Exception {
        BigInteger v = BigInteger.TEN.pow(25);
        System.out.println(rec(v));
    }

    static long rec(BigInteger v) {
        if (v.signum() == 0) {
            return 1;
        }
        if (memo.containsKey(v)) {
            return memo.get(v);
        }
        long ret = 0;
        if (v.remainder(TWO).signum() == 0) {
            ret += rec(v.divide(TWO));
            ret += rec(v.subtract(TWO).divide(TWO));
        } else {
            ret += rec(v.subtract(BigInteger.ONE).divide(TWO));
        }
        memo.put(v, ret);
        return ret;
    }
}
