#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    vector<long long> factor;
    long long n = 600851475143;
    for(long long i = 2; i <= n; i++) {
        if(n % i == 0) {
            factor.push_back(i);
            n /= i;
            i--;
        }
    }

    int res = 0;
    for(int i = 0; i < factor.size(); i++) {
        res = max(res, factor[i]);
    }

    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
