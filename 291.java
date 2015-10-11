import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
        final long bound = 50000000;
        long count = 0;
        for (long i = 1; i < bound; i++) {
            final BigInteger n = BigInteger.valueOf(2*i*(i+1) + 1);
            if (n.isProbablePrime(4)) {
                count++;
                if (count % 1000 == 0) {
                    System.out.println(count + " => " + n + " " + i);
                }
            }
        }
        System.out.println(count);  
    }
}
