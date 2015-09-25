/*
http://math.stackexchange.com/questions/163245/finding-sum-of-factors-of-a-number-using-prime-factorization
*/

#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

long long square(long long x) {
    return x * x;
}

long long power(int x, int y) {
    long long lx = x;
    if(y == 1) return lx;
    if(y % 2 == 0) return square(power(lx, y / 2));
    return lx * square(power(lx, y / 2));
}

int getFactorSum(int n) {
    if(n == 1) return 0;
    unordered_map<int, int> m;
    int input = n;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            m[i]++;
            n /= i;
            i--;
        }
    }

    int res = 1;
    unordered_map<int, int>::iterator it = m.begin();
    while(it != m.end()) {
        long long t = power(it->first, it->second + 1) - 1;
        t /= (it->first - 1);
        res *= t;
        it++;
    }

    return (res - input);
}

int main() {
    int N = 10001;
    vector<int> v(N, 0);
    for(int i = 1; i < N; i++) {
        v[i] = getFactorSum(i);
    }

    int res = 0;
    for(int i = 1; i < N; i++) {
        if(v[i] >= 1 && v[i] < N && (v[i] != i) && (v[v[i]] == i)) {
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
