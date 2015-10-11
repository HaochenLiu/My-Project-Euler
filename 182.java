public class Main {
    public static void main(String[] args) {
        long p = 1009;
        long q = 3643;
        long phi = (p-1)*(q-1);
        long sum = 0;
        for (long e = 2; e < phi; e++) {
            if (gcd(e, phi) > 1) {
                continue;
            }
            if (gcd(e-1, p-1) == 2 && gcd(e-1, q-1) == 2) {
                sum += e;
            }
        }
        System.out.println(sum);
    }
    
    private static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % t;
            a = t;
        }
        return a;
    }
}
