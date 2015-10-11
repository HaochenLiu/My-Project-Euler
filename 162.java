import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws Exception {
        BigInteger ans = BigInteger.ZERO;
        for (int len = 3; len <= 16; ++len) {
            BigInteger all = BigInteger.valueOf(16).pow(len - 1).multiply(BigInteger.valueOf(15));
            BigInteger f0 = BigInteger.valueOf(15).pow(len);
            BigInteger f1 = BigInteger.valueOf(15).pow(len - 1).multiply(BigInteger.valueOf(14));
            BigInteger fA = f1;
            BigInteger f01 = BigInteger.valueOf(14).pow(len);
            BigInteger f1A = BigInteger.valueOf(14).pow(len - 1).multiply(BigInteger.valueOf(13));
            BigInteger fA0 = f01;
            BigInteger f01A = BigInteger.valueOf(13).pow(len);
            ans = ans.add(all.subtract(f0).subtract(f1).subtract(fA).add(f01).add(f1A).add(fA0).subtract(f01A));
        }
        System.out.println(ans.toString(16).toUpperCase());
    }
}
