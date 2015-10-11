public class Main {

    public static void main(String[] args) throws Exception {
        System.out.println(solve((int)1e9));
    }

    static long solve(int r) {
        if (r <= 7) {
            return r * (r + 1) / 2;
        }
        long ans = 7 * 8 / 2;
        int rr = 7;
        while (rr * 7 <= r) {
            ans *= 7 * 8 / 2;
            rr *= 7;
        }
        int level = r / rr;
        ans *= level * (level + 1) / 2;
        ans += (r / rr + 1) * solve(r % rr);
        return ans;
    }
}
