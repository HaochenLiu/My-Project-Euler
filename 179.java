public class Main {

    public static void main(String[] args) throws Exception {
        int[] minDiv = new int[10000001];
        for (int i = 2; i <= 10000000; ++i) {
            if (minDiv[i] != 0) continue;
            for (int j = i * 2; j <= 10000000; j += i) {
                if (minDiv[j] == 0) minDiv[j] = i;
            }
        }
        int[] divs = new int[10000001];
        divs[1] = 1;
        for (int i = 2; i <= 10000000; ++i) {
            if (minDiv[i] == 0) {
                divs[i] = 2;
            } else {
                int v = i;
                int count = 1;
                while (v % minDiv[i] == 0) {
                    v /= minDiv[i];
                    ++count;
                }
                divs[i] = count * divs[v];
            }
        }
        int ans = 0;
        for (int i = 1; i < 10000000; ++i) {
            if (divs[i] == divs[i + 1]) {
                ++ans;
            }
        }
        System.out.println(ans);
    }
}
