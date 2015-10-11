import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static int s[] = new int[55];
    static int indexS = -1;
    static int SENTINEL = Integer.MIN_VALUE;
    static {
        Arrays.fill(s, SENTINEL);
    }

    public static void main(String args[]) {
        final int NUM_CUBOID = 50000;
        ArrayList<Cuboid> cubAdded = new ArrayList<Cuboid>();
        ArrayList<Cuboid> cubSubstracted = new ArrayList<Cuboid>();
        long totalVolume = 0;
        for (int i = 1; i <= NUM_CUBOID; i++) {
            Cuboid cuboid = nextCuboid();
            ArrayList<Cuboid> newCubAdded = new ArrayList<Cuboid>();
            ArrayList<Cuboid> newCubSubstracted = new ArrayList<Cuboid>();
            newCubAdded.add(cuboid);
            for (Cuboid c : cubAdded) {
                Cuboid inter = Cuboid.intersect(c, cuboid);
                if (inter != null) {
                    newCubSubstracted.add(inter);
                }
            }
            for (Cuboid c : cubSubstracted) {
                Cuboid inter = Cuboid.intersect(c, cuboid);
                if (inter != null) {
                    newCubAdded.add(inter);
                }
            }
            cubAdded.addAll(newCubAdded);
            cubSubstracted.addAll(newCubSubstracted);
        }
        for (Cuboid c : cubAdded) {
            totalVolume += c.volume();
        }
        for (Cuboid c : cubSubstracted) {
            totalVolume -= c.volume();
        }
        System.out.println(totalVolume);
    }

    static Cuboid nextCuboid() {
        return new Cuboid(nextS() % 10000, nextS() % 10000, nextS() % 10000,
                1 + nextS() % 399, 1 + nextS() % 399, 1 + nextS() % 399);
    }

    static int nextS() {
        indexS = (indexS + 1) % s.length;
        if (s[indexS] == SENTINEL) {
            s[indexS] = (int) ((100003 - 200003 * (indexS + 1) + 300007L
                    * (indexS + 1) * (indexS + 1) * (indexS + 1)) % 1000000);
        } else {
            s[indexS] = (s[(indexS + 31) % s.length] + s[indexS]) % 1000000;
        }
        return s[indexS];
    }
}

class Cuboid {
    int x0;
    int y0;
    int z0;
    int dx;
    int dy;
    int dz;

    Cuboid(int x0, int y0, int z0, int dx, int dy, int dz) {
        this.x0 = x0;
        this.y0 = y0;
        this.z0 = z0;
        this.dx = dx;
        this.dy = dy;
        this.dz = dz;
    }

    static Cuboid intersect(Cuboid c1, Cuboid c2) {
        int interX0 = Math.max(c1.x0, c2.x0);
        int interY0 = Math.max(c1.y0, c2.y0);
        int interZ0 = Math.max(c1.z0, c2.z0);
        int interX1 = Math.min(c1.x0 + c1.dx, c2.x0 + c2.dx);
        int interY1 = Math.min(c1.y0 + c1.dy, c2.y0 + c2.dy);
        int interZ1 = Math.min(c1.z0 + c1.dz, c2.z0 + c2.dz);
        if (interX0 >= interX1 || interY0 >= interY1 || interZ0 >= interZ1) {
            return null;
        }
        return new Cuboid(interX0, interY0, interZ0, interX1 - interX0, interY1
                - interY0, interZ1 - interZ0);
    }

    long volume() {
        return (long) dx * dy * dz;
    }
}
