import java.util.ArrayDeque;

public class Main {

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        final long size = 100000000;
        final long boundn = 1, boundd = 100;
        ArrayDeque<Long> list = new ArrayDeque<Long>();
        long leftn = 0, leftd = 1; // Farey number on the left
        long rghtn = 1, rghtd = 1; // Farey number on the right
        long count = 0;
        while (true) {
            long ambigd = 2 * leftd * rghtd; // get ambiguous number in this
                                                // interval
            if (ambigd <= size) {
                long ambign = leftd * rghtn + leftn * rghtd;
                if (ambign * boundd < boundn * ambigd)
                    count++; // count it if it is in range
                long medn = leftn + rghtn, medd = leftd + rghtd; // split
                                                                    // interval
                                                                    // by
                                                                    // mediant
                if ((medn * boundd <= boundn * medd)) {
                    list.push(leftd);
                    list.push(leftn); // save lhs interval
                    leftn = medn;
                    leftd = medd; // use rhs interval
                } else {
                    rghtd = medd;
                    rghtn = medn; // use lhs interval
                }
            } else { // bottomed out
                if (list.isEmpty())
                    break; // get next interval, if any
                rghtn = leftn;
                rghtd = leftd;
                leftn = list.pop();
                leftd = list.pop();
            }
        }
        System.out.println("Answer: " + count);

        long endTime = System.nanoTime();
        System.out.printf("Total Time: %.6f seconds\n",
                ((endTime - startTime) / 1000000000.0));
    }
}
