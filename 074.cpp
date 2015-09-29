/*
BF。
局部优化永无止境，但我懒得做了。
*/

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

long long fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

long long getFacSum(long long n) {
    long long res = 0;
    while(n) {
        res += fac[n % 10];
        n /= 10;
    }
    return res;
}

int main() {
    unordered_map<long long, int> m;
    int N = 1000000;
    int cnt = 60;
    int res = 0;
    for(long long i = 1; i < N; i++) {
        if(i % 10000 == 0) {
            cout<<"Search "<<i<<endl;
        }
        m.clear();
        m[i] = 1;
        int input = i;
        for(int j = 2; j <= cnt + 1; j++) {
            input = getFacSum(input);
            if(m.find(input) != m.end()) {
                if(j == cnt + 1) {
                    cout<<i<<endl;
                    res++;
                }
                break;
            } else {
                m[input] = j;
            }
        }
    }
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
