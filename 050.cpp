#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    int N = 1000000;
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
    v.push_back(0);
    unordered_map<int, bool> m;
    for(int i = 1; i < N; i++) {
        if(prime[i]) {
            m[i] = true;
            v.push_back(i);
        }
    }
    
    vector<long long> ps(v.size(), 0);
    partial_sum(v.begin(), v.end(), ps.begin());

    int sz = v.size();
    cout<<"v.size() "<<sz<<endl;

    int maxSize = 0;
    for(maxSize = 0; maxSize < sz; maxSize++) {
        if(ps[maxSize] > N) {
            break;
        }
    }
    cout<<"maxSize "<<maxSize<<endl;

    for(int i = maxSize - 1; i >= 1; i--) {
        for(int j = 0; j < sz - i; j++) {
            int t = ps[j + i] - ps[j];
            if(t < N && m.find(t) != m.end()) {
                cout<<"i "<<i<<endl;
                cout<<"j "<<j<<endl;
                cout<<"ps[j] "<<ps[j]<<endl;
                cout<<"ps[j + i] "<<ps[j + i]<<endl;
                cout<<"ps[j + i] - ps[j] "<<ps[j + i] - ps[j]<<endl;

                int wait = 0;
                cin>>wait;
            }
        }
    }
    
    cout<<"Result "<<endl;

    return 0; 
}
