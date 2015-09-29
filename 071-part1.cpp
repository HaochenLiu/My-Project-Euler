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

struct fraction {
    int n;
    int d;
};

fraction itof(int n, int d = 1) {
    fraction f;
    f.n = n;
    f.d = d;
    return f;
}

bool operator==(fraction x, fraction y) {
    if(x.d == 0 || y.d == 0) return false;
    return (x.n * y.d == y.n * x.d);
}

bool operator>(fraction x, fraction y) {
    if(x.d == 0 || y.d == 0) return false;
    return (x.n * y.d > y.n * x.d);
}

bool operator<(fraction x, fraction y) {
    if(x.d == 0 || y.d == 0) return false;
    return (x.n * y.d < y.n * x.d);
}

int main() {
    fraction thres = itof(3, 7);
    fraction res = itof(0);
    int N = 1000000;
    for(int d = 100; d <= N; d++) {
        int n;
        for(n = (int)(3.0 * d / 7.0); n >= 1; n--) {
            if(itof(n, d) < thres) {
                if(itof(n, d) > res) {
                    res = itof(n, d);
                }
                break;
            }
        }
    }

    cout<<"n "<<res.n<<" d "<<res.d<<endl;

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
