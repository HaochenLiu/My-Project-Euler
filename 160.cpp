#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

const ll MOD = 100000;
ll oddUnder100000;

ll power(ll b, ll p) {
    if (p == 0) return 1;
    if (p == 1) return b;
    ll ret = power((b*b)%MOD, p/2);
    if (p % 2 != 0) {
        ret *= b;
        ret %= MOD;
    }
    return ret;
}

pair<ll, ll> except5(ll limit){
    if (limit == 1){
        return make_pair(1, 0);
    } 
    auto sub = except5(limit / 2);
    sub.second += limit / 2 - limit / 10;
    ll mul = pow(oddUnder100000, limit / MOD);
    for (int i = 1, upper = limit % MOD; i <= upper; i += 2) {
        if (i % 5 == 0) continue;
        mul *= i;
        mul %= MOD;
    }
    mul *= sub.first;
    mul %= MOD;
    //    cout << "except5 " << limit << " " << mul << " " << sub.second << endl;
    return make_pair(mul, sub.second);
}

ll calc(ll limit) {
    if (limit < 5){
        ll ret = 1;
        for (ll i = 1; i <= limit; ++i) {
            ret *= i;
        }
        return ret % MOD;
    } 
    auto res = except5(limit);
    ll sub = calc(limit / 5);
    res.second -= limit / 5;
    ll ret = res.first;
    ret *= sub;
    ret %= MOD;
    ll p = power(2, res.second);
    ret *= p;
    ret %= MOD;
    //    cout << "calc " << limit << " " << ret << " " << res.first << endl;
    return ret;
}

int main(){
    oddUnder100000 = 1;
    for (int i = 1; i < MOD; i += 2) {
        if (i % 5 == 0) continue;
        oddUnder100000 *= i;
        oddUnder100000 %= MOD;
    }
    cout << calc(20) << endl;
    cout << calc(1000000000000ll) << endl;
    return 0;
}
