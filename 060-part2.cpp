/*
推广到5个数。如果N设为1000，根本跑不完。必须考虑优化问题。
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

bool* prime;
int N = 100;

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

int digitCnt(int n) {
    int res = 0;
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

int concat(int a, int b) {
    int digit = digitCnt(b);
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
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            v.push_back(i);
        }
    }
    int sz = v.size();
    cout<<"sz "<<sz<<endl;
    int n = 5;
    vector<int> p(n, 0);
    for(int i0 = 0; i0 < sz; i0++) {
        p[0] = v[i0];
        for(int i1 = i0 + 1; i1 < sz; i1++) {
            p[1] = v[i1];
            for(int i2 = i1 + 1; i2 < sz; i2++) {
                p[2] = v[i2];
                for(int i3 = i2 + 1; i3 < sz; i3++) {
                    p[3] = v[i3];
                    for(int i4 = i3 + 1; i4 < sz; i4++) {
                        p[4] = v[i4];
                        bool flag = true;
                        for(int i = 0; i < n; i++) {
                            for(int j = i + 1; j < n; j++) {
                                if(!isPrime(concat(p[i], p[j])) || !isPrime(concat(p[j], p[i]))) {
                                    flag = false;
                                    break;
                                }
                            }
                            if(!flag) {
                                break;
                            }
                        }
                        if(flag) {
                            for(int i = 0; i < n; i++) {
                                cout<<p[i]<<endl;
                            }
                            cout<<endl;
                        }
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
