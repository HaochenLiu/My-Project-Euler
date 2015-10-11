import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {

    public static void main(String[] args) throws Exception {
        Deque<Integer> q1 = new ArrayDeque<Integer>();
        Deque<Integer> q2 = new ArrayDeque<Integer>();
        for (int k = 1; k <= 31; ++k) {
            q2.add((int) ((100003l - 200003l * k + 300007l * k * k * k) % 1000000));
        }
        for (int k = 32; k <= 55; ++k) {
            q1.add((int) ((100003l - 200003l * k + 300007l * k * k * k) % 1000000));
        }
        UnionFind uf = new UnionFind(1000000);
        for (int i = 1;; ++i) {
            int mid = q1.poll();
            int caller = q2.poll();
            int s = (caller + mid) % 1000000;
            q1.add(s);
            q2.add(mid);
            mid = q1.poll();
            int callee = q2.poll();
            s = (callee + mid) % 1000000;
            q1.add(s);
            q2.add(mid);
            uf.union(caller, callee);
            if (caller == callee) --i;
            if (uf.size(524287) >= 990000) {
                System.out.println(i);
                return;
            }
        }
    }

    static class UnionFind {
        int[] set;

        UnionFind(int n) {
            set = new int[n];
            Arrays.fill(set, -1);
        }

        void union(int a, int b) {
            int rtA = root(a);
            int rtb = root(b);
            if (rtA == rtb) {
                return;
            }
            set[rtA] += set[rtb];
            set[rtb] = rtA;
        }

        boolean find(int a, int b) {
            return root(a) == root(b);
        }

        int root(int a) {
            if (set[a] < 0) {
                return a;
            } else {
                set[a] = root(set[a]);
                return set[a];
            }
        }

        int size(int a) {
            return -set[root(a)];
        }
    }
}
