import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        long count = 0;
        for (long n = 2; n <= 50_000_000; n++) {
            if (n % 1_000_000 == 0) {
                System.out.printf("Performance counter: %d\n", n);
                System.out.printf("Current count: %d\n", count);
            }
            BigInteger t = BigInteger.valueOf(2)
                    .multiply(BigInteger.valueOf(n).pow(2))
                    .add(BigInteger.ONE.negate());
            if (t.isProbablePrime(4)) {
                count++;
            }
        }
        System.out.println(count);
    }
}
