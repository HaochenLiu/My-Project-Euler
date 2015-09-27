/*
得到一个解：8384^3 = 589323567104
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

long long N = 10000;

long long cube(long long n) {
    return (n * n * n);
}

string lltostr(long long n) {
    if(n == 0) return "0";
    string res = "";
    while(n) {
        res.append(1, '0' + n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    unordered_map<string, int> m;
    for(long long i = 1; i < N; i++) {
        string t = lltostr(cube(i));
        sort(t.begin(), t.end());
        m[t]++;
        if(m[t] == 5) {
            cout<<t<<endl;
            cout<<"i "<<i<<" cube(i) "<<cube(i)<<endl;
            break;
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
