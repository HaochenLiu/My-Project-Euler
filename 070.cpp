/*
https://en.wikipedia.org/wiki/Euler%27s_totient_function
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

string itos(int n) {
    string res = "";
    if(n == 0) return "0";
    if(n < 0) {
        res = "-";
        res += itos(-n);
        return res;
    }
    while(n > 0) {
        res.append(1, '0' + n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool hasSameDigit(int a, int b) {
    string sa = itos(a);
    string sb = itos(b);
    if(sa.size() != sb.size()) return false;
    int exist[256];
    memset(exist, 0, sizeof(exist));
    for(int i = 0; i < sa.size(); i++) {
        exist[sa[i]]++;
        exist[sb[i]]--;
    }
    for(int i = 0; i < 256; i++) {
        if(exist[i] != 0) {
            return false;
        }
    }

    return true;
}

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
    int N = 10000000;
    phiVal = new int[N];
    memset(phiVal, 0, sizeof(int) * N);
    double minVal = (double)INT_MAX;
    int res = 0;
    for(int i = 2; i < N; i++) {
        int t = phi(i);
        if(hasSameDigit(i, t)) {
            if((double)i / (double)t < minVal) {
                minVal = (double)i / (double)t;
                res = i;
                cout<<i<<" "<<t<<" "<<minVal<<endl;
            }
        }
    }
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
