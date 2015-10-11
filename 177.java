public class PE177 {

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        int nonsimilarintegerangledquadrilaterals = 0;
        double[] sin = new double[180], cos = new double[180];

        for (int x = 0; x < 180; sin[x] = Math.sin(Math.toRadians(x)), cos[x] = Math
                .cos(Math.toRadians(x++)))
            ;
        for (int a = 2; a <= 90; a++)
            for (int b = 1; b < 180 - a; b++) {

                double c = sin[b] / sin[a + b];
                for (int d = Math.max(a, b + 1); d <= 180 - a; d++)
                    for (int f = d == a ? b : 1; f < Math.min(a, 180 - d); f++) {

                        double e = sin[d] / sin[d + f];
                        double x = Math.toDegrees(Math.atan2(sin[f] * e
                                - sin[a] * c, cos[f] * e - cos[a] * c));
                        int y = (int) Math.round(x);
                        int g = 180 - a + y, h = 180 - d - y;
                        if (h < a)
                            break;
                        if (g < d)
                            continue;
                        if ((d == g) && (f > a / 2))
                            continue;
                        if ((h == a) && (b > d / 2))
                            continue;
                        if (Math.abs(x - y) < 1.0E-10)
                            nonsimilarintegerangledquadrilaterals++;
                    }
            }
        // System.out.println("non-similar integer angled quadrilaterals");
        System.out.println("Answer: " + nonsimilarintegerangledquadrilaterals);

        long endTime = System.nanoTime();
        System.out.printf("Total Time: %.6f seconds\n",
                ((endTime - startTime) / 1000000000.0));
    }
}
