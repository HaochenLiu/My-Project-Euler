import java.util.Arrays;
import java.util.HashMap;

public class Main {

    static HashMap<State, Long> memo = new HashMap<State, Long>();
    static final int SIZE = 70;

    public static void main(String[] args) throws Exception {
        int[] c = new int[5];
        c[1] = 1;
        System.out.println(rec(1, c, false, 1) * 2);
    }

    static long rec(int prev, int[] c, boolean clock, int depth) {
        if (depth == SIZE) {
            return 1;
        }
        State st = new State(prev, c, clock);
        if (memo.containsKey(st)) {
            return memo.get(st);
        }
        long ret = 0;
        if (c[prev] < SIZE / 5) {
            c[prev]++;
            ret += rec(prev, c, !clock, depth + 1);
            c[prev]--;
        }
        int next = (prev + (clock ? 4 : 1)) % 5;
        if (c[next] < SIZE / 5) {
            c[next]++;
            ret += rec(next, c, clock, depth + 1);
            c[next]--;
        }
        memo.put(st, ret);
        return ret;
    }

    static class State {
        int prev;
        int[] count;
        boolean clock;

        State(int prev, int[] c, boolean clock) {
            this.prev = prev;
            this.count = c.clone();
            this.clock = clock;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (clock ? 1231 : 1237);
            result = prime * result + Arrays.hashCode(count);
            result = prime * result + prev;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            State other = (State) obj;
            if (clock != other.clock) return false;
            if (!Arrays.equals(count, other.count)) return false;
            if (prev != other.prev) return false;
            return true;
        }

    }
}
