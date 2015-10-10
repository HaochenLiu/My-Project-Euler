#include<thread.h>

#define true 1
#define false 0
#define NT 125

char *prime;
const int N = 100000000;
int cnt;
long long* p;
int* bound;
long long* ps;

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

void* ThreadFunc(void* param) {
    int a;
    int b;
    int i = (int)param;
    long long sum = 0;
    for(a = bound[i]; a < bound[i + 1]; a++) {
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
    ps[i] = sum;
    printf("TID = %d sum[%d] = %lld\n", thr_self(), i, sum);
}

int main() {
    int i;
    int j;

    prime = malloc(N * sizeof(int));
    memset(prime, true, sizeof(char) * N);
    prime[0] = false;
    prime[1] = false;
    int sr = sqrt(N);
    for(i = 2; i <= sqrt(N); i++) {
        for(j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    cnt = 0;
    for(i = 0; i < N; i++) {
        if(prime[i]) {
            cnt++;
        }
    }
    printf("prime cnt = %d\n", cnt);

    p = malloc(sizeof(long long) * cnt);
    
    j = 0;
    for(i = 0; i < N; i++) {
        if(prime[i]) {
            p[j++] = i;
        }
    }

    bound = malloc((NT + 1) * sizeof(int));
    ps = malloc(NT * sizeof(long long));
    memset(ps, 0, sizeof(int) * NT);
    for(i = 0; i < NT; i++) {
        bound[i] = cnt / NT * i;
    }
    bound[NT] = cnt;

    thread_t* threadID = malloc(sizeof(thread_t) * NT);
    for(i = 0; i < NT; i++) {
        thr_create(NULL, 0, ThreadFunc, (void*)i, NULL, &threadID[i]);
    }

    for(i = 0; i < NT; i++) {
        thr_join(threadID[i], NULL, NULL);
    }
    
    long long sum = 0;
    for(i = 0; i < NT; i++) {
        sum += ps[i];
    }
    printf("sum = %lld\n", sum);

    return 0; 
}
