/*
首先2不可能。
其次考虑模3的情况。
如果有两个素数，一个模3余1，一个模3余2。那么连起来一定是合数。
所以，要么就11111，要么就22222。
还可能是第一个数是3，然后1111或者2222。可以由此做剪枝。
反复调高N2，达到1100。得到一组26033。
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

bool* prime;
int N = 100000000;

bool isPrime(long long n) {
    if(n < N) return prime[n];

    long long rt = sqrt((double)n);
    for(int i = 2; i <= rt; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

long long digitCnt(long long n) {
    long long res = 0;
    while(n) {
        res++;
        n /= 10;
    }
    return res;
}

int square(int x) {
    return (x * x);
}

int power(int x, int y) {
    if(x == 0) return 0;
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y % 2 == 0) return square(power(x, y / 2));
    return (x * square(power(x, y / 2)));
}

long long concat(long long a, long long b) {
    long long digit = digitCnt(b);
    return (a * power(10, digit) + b);
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

    vector<int> v;
    for(int i = 3; i < N; i++) {
        if(prime[i]) {
            v.push_back(i);
        }
    }

    int N2 = 1100;
    int sz = min(N2, (int)v.size());
    cout<<"sz "<<sz<<" maxPrime "<<v[sz - 1]<<endl;
    int n = 5;
    vector<int> p(n, 0);
    for(int i0 = 0; i0 < sz; i0++) {
        p[0] = v[i0];
        for(int i1 = i0 + 1; i1 < sz; i1++) {
            p[1] = v[i1];
            if(p[0] != 3 && p[0] % 3 != p[1] % 3) {
                continue;
            }
            if(!isPrime(concat(p[0], p[1])) || !isPrime(concat(p[1], p[0]))) {
                continue;
            }
            for(int i2 = i1 + 1; i2 < sz; i2++) {
                p[2] = v[i2];
                if(p[1] % 3 != p[2] % 3) {
                    continue;
                }
                if(!isPrime(concat(p[0], p[2])) || !isPrime(concat(p[2], p[0]))) {
                    continue;
                }
                if(!isPrime(concat(p[1], p[2])) || !isPrime(concat(p[2], p[1]))) {
                    continue;
                }
                for(int i3 = i2 + 1; i3 < sz; i3++) {
                    p[3] = v[i3];
                    if(p[1] % 3 != p[3] % 3) {
                        continue;
                    }
                    if(!isPrime(concat(p[0], p[3])) || !isPrime(concat(p[3], p[0]))) {
                        continue;
                    }
                    if(!isPrime(concat(p[1], p[3])) || !isPrime(concat(p[3], p[1]))) {
                        continue;
                    }
                    if(!isPrime(concat(p[2], p[3])) || !isPrime(concat(p[3], p[2]))) {
                        continue;
                    }
                    for(int i4 = i3 + 1; i4 < sz; i4++) {
                        p[4] = v[i4];
                        if(p[1] % 3 != p[4] % 3) {
                            continue;
                        }
                        if(!isPrime(concat(p[0], p[4])) || !isPrime(concat(p[4], p[0]))) {
                            continue;
                        }
                        if(!isPrime(concat(p[1], p[4])) || !isPrime(concat(p[4], p[1]))) {
                            continue;
                        }
                        if(!isPrime(concat(p[2], p[4])) || !isPrime(concat(p[4], p[2]))) {
                            continue;
                        }
                        if(!isPrime(concat(p[3], p[4])) || !isPrime(concat(p[4], p[3]))) {
                            continue;
                        }
                        int sum = 0;
                        for(int i = 0; i < n; i++) {
                            cout<<p[i]<<endl;
                            sum += p[i];
                        }
                        cout<<"sum = "<<sum<<endl;
                    }
                }
            }
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
