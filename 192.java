import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        long m = 1;
        long limit = 1000000;
        limit = limit * limit;
        long total = 0;
        for (long N = 2; N <= 100000; N++) {
            if ((m + 1) * (m + 1) == N) {
                m++;
                continue;
            }

            long A0 = 0;
            long A1 = 1;
            long Q1 = N;
            long g = m;
            long r1 = g;
            long P2 = 0;
            long Q2 = 1;
            long B0 = 1;
            long B1 = 0;
            long A2;
            long B2;

            while (true) {
                long r2 = (g + P2) % Q2;
                long q2 = (g + P2) / Q2;

                A2 = q2 * A1 + A0;
                B2 = q2 * B1 + B0;
                long P3 = g - r2;
                long Q3 = Q1 + q2 * (r2 - r1);

                // System.out.println(A2+" "+B2);

                if (B2 > limit)
                    break;

                A0 = A1;
                A1 = A2;
                B0 = B1;
                B1 = B2;
                r1 = r2;
                Q1 = Q2;
                Q2 = Q3;
                P2 = P3;
            }

            double x1 = A1;
            double y1 = B1;

            long u1 = A0;
            long v1 = B0;
            while (v1 <= limit) {
                u1 = u1 + A1;
                v1 = v1 + B1;
            }

            u1 = u1 - A1;
            v1 = v1 - B1;

            double x2 = u1;
            double y2 = v1;

            double z = Math.sqrt(N);

            double x = x1 / y1;
            double y = x2 / y2;

            BigInteger s1 = (BigInteger.valueOf(A1)).multiply(BigInteger
                    .valueOf(A1));
            BigInteger s2 = (BigInteger.valueOf(B1)).multiply(BigInteger
                    .valueOf(B1));

            BigInteger t1 = (BigInteger.valueOf(u1)).multiply(BigInteger
                    .valueOf(u1));
            BigInteger t2 = (BigInteger.valueOf(v1)).multiply(BigInteger
                    .valueOf(v1));

            BigInteger s3 = (s1.subtract(s2.multiply(BigInteger.valueOf(N))));
            BigInteger t3 = (t1.subtract(t2.multiply(BigInteger.valueOf(N))));

            BigInteger w1 = (s2).multiply(t3);
            BigInteger w2 = (t2).multiply(s3);

            if (w1.compareTo(BigInteger.ZERO) < 0) {
                w1 = (BigInteger.ZERO).subtract(w1);
            }
            if (w2.compareTo(BigInteger.ZERO) < 0) {
                w2 = (BigInteger.ZERO).subtract(w2);
            }

            // System.out.println(u1+" "+v1+" "+A1+" "+B1);

            if ((w1.compareTo(w2) < 0) && (v1 <= limit)) {
                total = total + (v1);
                // System.out.println(N+"  "+(u1)+"/"+(v1));
            } else {
                total = total + B1;
                // System.out.println(N+"  "+(A1)+"/"+(B1));
            }
        }

        System.out.println("Answer: " + total);

        long endTime = System.nanoTime();
        System.out.printf("Total Time: %.6f seconds\n",
                ((endTime - startTime) / 1000000000.0));
    }
}
