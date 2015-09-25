#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

long long square(long long x) {
    return x * x;
}

long long power(long long x, int y) {
    long long lx = x;
    if(y == 1) return lx;
    if(y % 2 == 0) return square(power(lx, y / 2));
    return lx * square(power(lx, y / 2));
}

int getFactorSum(int n) {
    if(n == 1) return 0;
    unordered_map<int, int> m;
    int input = n;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            m[i]++;
            n /= i;
            i--;
        }
    }

    int res = 1;
    unordered_map<int, int>::iterator it = m.begin();
    while(it != m.end()) {
        long long t = power(it->first, it->second + 1) - 1;
        t /= (it->first - 1);
        res *= t;
        it++;
    }

    return (res - input);
}

bool isAbundant(int n) {
    return (getFactorSum(n) > n);
}

int main() {
    int N = 28124;
    vector<int> abundant;
    for(int i = 1; i < N; i++) {
        if(isAbundant(i)) {
            abundant.push_back(i);
        }
    }

    cout<<"abundant.size() "<<abundant.size()<<endl;
    vector<bool> sum(N, false);
    for(int i = 0; i < abundant.size(); i++) {
        for(int j = i; j < abundant.size(); j++) {
            if(abundant[i] + abundant[j] >= N) {
                break;
            }
            sum[abundant[i] + abundant[j]] = true;
        }
    }

    int res = 0;
    for(int i = 1; i < N; i++) {
        if(!sum[i]) {
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
