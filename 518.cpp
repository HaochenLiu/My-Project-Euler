#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

bool* prime;
const int N = 100000000;

bool isGeoSeq(long long a, long long b, long long c) {
    return (a * c == b * b);
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    prime = new bool[N];
    memset(prime, true, sizeof(bool) * N);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(prime[i]) {
            cnt++;
        }
    }
    cout<<"prime cnt = "<<cnt<<endl;

    long long* p = new long long[cnt];
    int j = 0;
    for(int i = 0; i < N; i++) {
        if(prime[i]) {
            p[j++] = i;
        }
    }
    
    long long sum = 0;
    for(int a = 0; a < cnt; a++) {
        if(a % 10000 == 0) cout<<"a "<<a<<endl;
        for(int b = a + 1; b < cnt; b++) {
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
    cout<<"sum = "<<sum<<endl;

    int wait;
    cin>>wait;

    return 0; 
}
