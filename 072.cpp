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

int* phiVal;

long long phi(long long x) {
    long long input = x;
    long long ret = 1;
    long long i;
    long long pow;
    for (i = 2; x != 1; i++) {
        if(phiVal[x] == 0) {
            pow = 1;
            if(i > (int)sqrt((double)x)) {
                break;
            }
            while (x % i == 0)  {
                x /= i;
                pow *= i;
            }
            ret *= (pow - (pow / i));
        } else {
            ret *= phiVal[x];
            phiVal[input] = ret;
            return ret;
        }
    }
    if(x != 1) {
        ret *= (x - 1);
    }
    phiVal[input] = ret;
    return ret;
}

int main() {
    int N = 1000000;
    phiVal = new int[N + 1];
    memset(phiVal, 0, sizeof(int) * (N + 1));
    long long res = 0;
    for(int i = 2; i <= N; i++) {
        long long t = phi(i);
        res += t;
    }

    cout<<"Result "<<res<<endl;
    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
