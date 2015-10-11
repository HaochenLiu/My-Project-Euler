#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

const ll MOD = 1000000000;
ll fact19 = 1;
set<int> square;
ll ans = 0;
int c[10] = {};

ll combination(){
    ll ret = fact19;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 2; j <= c[i]; ++j) {
            ret /= j;
        }
    }
    return ret;
}

void sumup(){
    for (int i = 1; i <= 9; ++i) {
        if(c[i] == 0) continue;
        --c[i];
        ll add = i * combination();
        ++c[i];
        for (int i = 0; i < 9; ++i) {
            ans += add;
            ans %= MOD;
            add *= 10;
            add %= MOD;
        }
    }
}

void rec(int sum, int depth, int rest){
    if (depth == 0) {
        c[0] = rest;
        if (square.count(sum) != 0) sumup();
        return;
    }
    for (int i = 0; i <= rest; ++i) {
        c[depth] = i;
        rec(sum + i * depth*depth, depth - 1, rest - i);
    }
}

int main(){
    for (int i = 2; i <= 19; ++i) {
        fact19 *= i;
    }
    for (int i = 1; i*i <= 20*9*9; ++i) {
        square.insert(i*i);
    }
    rec(0, 9, 20);
    cout << ans << endl;
    return 0;
}
