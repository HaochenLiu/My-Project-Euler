#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;

ll ans = 1;

template<int N>
vector<ll> primes(){
    bitset<N+1> bs;
    vector<ll> ret;
    for (int i = 2; i <= N; ++i) {
        if (!bs[i]) {
            ret.push_back(i);
            for (ll j = (ll)i*i; j <= N; j += i) {
                bs.set(j);
            }
        }
    }
    return ret;
}

const int SIZE = 64000000;
vector<ll> ps = primes<SIZE>();

bool isSquare(ll v){
    ll sq = (ll)(sqrt(v) + 0.00001);
    return sq*sq == v;
}

void rec(ll sum, ll cur, int ind){
    for (size_t i = ind; i < ps.size(); ++i) {
        ll c = cur*ps[i];
        if (c >= SIZE) break;
        ll add = 1 + ps[i]*ps[i];
        while (c < SIZE) {
            if (isSquare(sum*add)) {
                cout << c << " " << sum*add << endl;
                ans += c;
            }
            rec(sum*add, c, i+1);
            c *= ps[i];
            add = add * ps[i] * ps[i] + 1;
        }
    }
}

int main(){
    cout << "ps.size() : " << ps.size() << endl;
    rec(1, 1, 0);
    cout << ans << endl;
    return 0;
}
