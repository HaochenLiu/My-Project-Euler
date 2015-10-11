public class Main {

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        int size = 10;
        double k1 = 1; // choose curvature 1 for the 3 equal circles
        double k0 = k1 * (3 - 2 * Math.sqrt(3)); // get curvature of the outer
                                                    // circle
        double a0 = 1 / (k0 * k0); // area of outer circle
        double a1 = 3 / (k1 * k1); // area of 3 inner circles
        a1 += 3 * getArea(k0, k1, k1, size); // fill three outer gaps
        a1 += getArea(k1, k1, k1, size); // fill centre gap
        System.out.println("Answer: "
                + String.format("%.6g%n", ((a0 - a1) / a0))); // report
                                                                // resulting
                                                                // fraction

        long endTime = System.nanoTime();
        System.out.printf("Total Time: %.6f seconds\n",
                ((endTime - startTime) / 1000000000.0));
    }

    static double getArea(double k1, double k2, double k3, int depth) {
        if (depth == 0)
            return 0.0;
        // calculate circle curvature of inside circle
        double k4 = k1 + k2 + k3 + 2 * Math.sqrt(k1 * k2 + k2 * k3 + k3 * k1);
        double a = 1 / (k4 * k4); // circle area
        a += getArea(k1, k2, k4, depth - 1); // add areas if inbetween fillings
        a += getArea(k2, k3, k4, depth - 1);
        a += getArea(k3, k1, k4, depth - 1);
        return a;
    }
}
