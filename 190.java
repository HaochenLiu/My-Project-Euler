import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger sum = BigInteger.ZERO;
        for (int m = 2; m <= 15; m++) {
            sum = sum.add(getMaximizedWeightedProduct(m));
        }
        System.out.println(sum);
    }
    
    private static BigInteger getMaximizedWeightedProduct(int m) {
        BigInteger n = BigInteger.valueOf(2).pow(m*(m+1)/2);
        BigInteger d = BigInteger.valueOf(m+1).pow(m*(m+1)/2);
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < i; j++) {
                n = n.multiply(BigInteger.valueOf(i));
            }
        }
        return n.divide(d);
    }
}
