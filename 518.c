#define true 1
#define false 0

char *prime;
const int N = 100;

char isGeoSeq(long long a, long long b, long long c) {
    return (a * c == b * b);
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int sqrt(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int i = 1;
    for(i = 1; i <= n; i++) {
	if(i * i == n) return i;
	if(i * i > n) return i - 1;
    }
    return -1;
}

int main() {
    prime = malloc(N * sizeof(int));
    memset(prime, true, sizeof(char) * N);
    prime[0] = false;
    prime[1] = false;
    int sr = sqrt(N);
    int i;
    int j;
    int a;
    int b;
    for(i = 2; i <= sqrt(N); i++) {
        for(j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    int cnt = 0;
    for(i = 0; i < N; i++) {
        if(prime[i]) {
            cnt++;
        }
    }
    printf("prime cnt = %d\n", cnt);

    long long* p = malloc(sizeof(long long) * cnt);
    
    j = 0;
    for(i = 0; i < N; i++) {
        if(prime[i]) {
            p[j++] = i;
        }
    }
    
    long long sum = 0;
    for(a = 0; a < cnt; a++) {
        if(a % 10000 == 0) printf("calulated %d\n", a);
        for(b = a + 1; b < cnt; b++) {
            long long t = (p[b] + 1) * (p[b] + 1) / (p[a] + 1) - 1;
            if(t >= N) break;
            if((p[b] + 1) * (p[b] + 1) % (p[a] + 1) != 0) continue;
            if(prime[t]) {
                sum += p[a];
                sum += p[b];
                sum += t;
            }
        }
    }
    printf("sum = %lld\n", sum);

    return 0; 
}
