import java.util.HashMap;

public class Main {

    static HashMap<Integer, Long> map = new HashMap<Integer, Long>();

    public static void main(String[] args) throws Exception {
        for (int i = 1; 2 * i <= 32; i += 3) {
            int t = (32 - i * 2) / 3;
            rec(i, t, 0, 0);
        }
        for (int i = 1; i < 10; ++i) {
            HashMap<Integer, Long> next = new HashMap<Integer, Long>();
            for (Integer cur : map.keySet()) {
                next.put(cur, 0l);
                for (Integer prev : map.keySet()) {
                    if ((cur & prev) == 0) {
                        next.put(cur, next.get(cur) + map.get(prev));
                    }
                }
            }
            map = next;
        }
        long ans = 0;
        for (Integer key : map.keySet()) {
            ans += map.get(key);
        }
        System.out.println(ans);
    }

    static void rec(int s, int t, int p, int v) {
        if (s != 0) {
            if (s == 1 && t == 0) {
                map.put(v, 1l);
            } else {
                rec(s - 1, t, p + 2, v | (1 << (p + 1)));
            }
        }
        if (t != 0) {
            if (t == 1 && s == 0) {
                map.put(v, 1l);
            } else {
                rec(s, t - 1, p + 3, v | (1 << (p + 2)));
            }
        }
    }
}
