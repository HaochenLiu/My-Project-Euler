/*
对每一个N，求出srn，为开方后的整数。
比如N=23, srn=4。
a+1/(b*sqrt(n)+c)/d
得出递推公式：
ai = (b(i-1)*srn+c(i-1))/d(i-1)
bi = d(i-1)*b(i-1)
ci = (ai*d(i-1)-c(i-1))*d(i-1)
di = b(i-1)^2*N-(ai*d(i-1)-c(i-1))^2

unordered_map<vector<int>, int> m;
不能用。只能把vector搞成一个hash。
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

long long gcd(long long a, long long b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool isSquare(int n) {
    int t = (int)sqrt((double)n);
    return (t * t == n);
}

long long getHash(vector<int> v) {
    long long res = 0;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        res *= 10000;
        res += v[i];
    }
    return res;
}

int getPeriod(int n) {
    int srn = (int)sqrt((double)n);
    vector<int> idx;
    idx.resize(4);
    unordered_map<long long, int> m;
    idx[0] = srn;
    idx[1] = 1;
    idx[2] = srn;
    idx[3] = n - srn * srn;
    m[getHash(idx)] = 1;
    while(true) {
        vector<int> tmp;
        tmp.resize(4);
        tmp[0] = (idx[1] * srn + idx[2]) / idx[3];
        tmp[1] = idx[1] * idx[3];
        tmp[2] = (tmp[0] * idx[3] - idx[2]) * idx[3];
        tmp[3] = idx[1] * idx[1] * n - (idx[2] - tmp[0] * idx[3]) * (idx[2] - tmp[0] * idx[3]);
        int g = gcd(tmp[1], tmp[2]);
        g = gcd(g, tmp[3]);
        tmp[1] /= g;
        tmp[2] /= g;
        tmp[3] /= g;
        int sz = m.size();
        if(m.find(getHash(tmp)) != m.end()) {
            return (sz - m[getHash(tmp)] + 1);
        } else {
            m[getHash(tmp)] = sz + 1;
            idx = tmp;
        }
    }
}

int main() {
    int N = 10000;
    int res = 0;
    for(int i = 2; i <= N; i++) {
        if(isSquare(i)) {
            continue;
        }
        if(getPeriod(i) % 2 == 1) {
            res++;
        }
    }
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
