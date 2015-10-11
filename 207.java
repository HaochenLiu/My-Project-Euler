public class Main {

    public static void main(String[] args) throws Exception {
        int pow2 = 2;
        int count = 0;
        for (int i = 1;; ++i) {
            if (i + 1 == pow2) {
                ++count;
                pow2 *= 2;
            }
            if (count * 12345 < i) {
                System.out.println((long) i * i + i);
                return;
            }
        }
    }
}
