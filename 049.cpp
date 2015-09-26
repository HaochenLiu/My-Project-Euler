#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
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

    vector<int> v;
    unordered_map<int, bool> m;
    for(int i = 1000; i < N; i++) {
        if(prime[i]) {
            m[i] = true;
            v.push_back(i);
        }
    }

    int sz = v.size();
    for(int i = 0; i < sz; i++) {
        for(int j = i + 2; j < sz; j++) {
            if(hasSameDigit(v[i], v[j])) {
                int mid = (v[i] + v[j]) / 2;
                if(m.find(mid) != m.end() && hasSameDigit(v[i], mid)) {
                    cout<<v[i]<<" "<<mid<<" "<<v[j]<<endl;
                }
            }
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
