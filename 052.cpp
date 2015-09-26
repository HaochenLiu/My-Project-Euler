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
    int N = 1000000;
    for(int i = 1; i < N; i++) {
        bool flag = true;
        for(int j = 2; j <= 6; j++) {
            if(!hasSameDigit(i, i * j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout<<i<<endl;
            break;
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
