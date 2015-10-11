import java.math.BigInteger;
import java.util.TreeSet;
import static java.lang.Math.min;

public class Main {

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        TreeSet<Long> set = new TreeSet<Long>();
        int count = 0;
        long max = Long.MAX_VALUE;
        for (long v = 1;; v++) {
            if (!prime(v))
                continue;
            long x = v * v * v;
            if (x > max)
                break;
            for (long w = 1;; w++) {
                if (v == w)
                    continue;
                if (!prime(w))
                    continue;
                long n = x * w * w;
                if (n > max)
                    break;
                String s = n + "";
                if (s.contains("200")) {
                    boolean succ = true;
                    char ch[] = s.toCharArray();
                    out: for (int i = 0; i < ch.length; i++) {
                        char c = ch[i];
                        for (ch[i] = i == 0 ? '1' : '0'; ch[i] <= '9'; ch[i]++) {
                            if (prime(new BigInteger(new String(ch)))) {
                                succ = false;
                                break out;
                            }
                        }
                        ch[i] = c;
                    }
                    if (succ) {
                        set.add(n);
                        if (set.size() > 200) {
                            while (set.size() > 200) {
                                set.pollLast();
                            }
                            max = min(max, set.last());
                        }
                        System.out.println(++count + ". n = " + n);
                    }
                }
            }
        }
        System.out.println("Answer: " + set.last());

        long endTime = System.nanoTime();
        System.out.printf("Total Time: %.6f seconds\n",
                ((endTime - startTime) / 1000000000.0));
    }

    static boolean prime(long n) {
        return prime(BigInteger.valueOf(n));
    }

    static boolean prime(BigInteger n) {
        return n.isProbablePrime(8);
    }
}
