/*
如果代替1位，或者2位，那么不可能出现8个素数。因为10个数字，至少得有3个被3整除的。去掉两个，还有1个。不满足条件。
所以必须代替3位，或者3的倍数位。
如果原数是3位数，则只有一种情况XXX，都不是素数，不满足条件。
考虑原数是4位数的情况：YXXX, XYXX, XXYX, XXXY。
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

int getFourDigit(int a, int b, int c, int d) {
    return (1000 * a + 100 * b + 10 * c + d);
}

int main() {
    int N = 10000;
    bool* prime = new bool[N];
    memset(prime, true, sizeof(bool) * N);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }
    
    int res = 0;

    int Y;
    int X;

    /* YXXX */
    for(Y = 1; Y <= 9; Y++) {
        int cnt = 0;
        int t;
        for(X = 0; X <= 9; X++) {
            t = getFourDigit(Y, X, X, X);
            if(prime[t]) {
                cnt++;
            }
        }
        if(cnt >= 8) {
            cout<<"Y "<<Y<<" X "<<X<<" num "<<getFourDigit(Y, X, X, X)<<endl;
        }
    }

    /* XYXX */
    for(Y = 0; Y <= 9; Y++) {
        int cnt = 0;
        int t;
        for(X = 1; X <= 9; X++) {
            t = getFourDigit(X, Y, X, X);
            if(prime[t]) {
                cnt++;
            }
        }
        if(cnt >= 8) {
            cout<<"Y "<<Y<<" X "<<X<<" num "<<getFourDigit(X, Y, X, X)<<endl;
        }
    }

    /* XXYX */
    for(Y = 0; Y <= 9; Y++) {
        int cnt = 0;
        int t;
        for(X = 1; X <= 9; X++) {
            t = getFourDigit(X, X, Y, X);
            if(prime[t]) {
                cnt++;
            }
        }
        if(cnt >= 8) {
            cout<<"Y "<<Y<<" X "<<X<<" num "<<getFourDigit(X, X, Y, X)<<endl;
        }
    }

    /* XXXY */
    for(Y = 0; Y <= 9; Y++) {
        int cnt = 0;
        int t;
        for(X = 1; X <= 9; X++) {
            t = getFourDigit(X, X, X, Y);
            if(prime[t]) {
                cnt++;
            }
        }
        if(cnt >= 8) {
            cout<<"Y "<<Y<<" X "<<X<<" num "<<getFourDigit(X, X, X, Y)<<endl;
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
