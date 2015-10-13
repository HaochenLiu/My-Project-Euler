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
#include <queue>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
    long long segment = 1000000;
    long long idx = 1;
    long long maxIdx = 100;
    long long cnt = 0;
    long long maxCnt = segment;
    long long* allPrime = new long long[maxCnt];
    memset(allPrime, 0, maxCnt * sizeof(long long));
    bool* prime = new bool[segment];
    memset(prime, true, segment * sizeof(bool));

    for(long long i = 2; i <= (long long)sqrt((double)segment); i++) {
        for(long long j = 2 * i; j < segment; j += i) {
            prime[j] = false;
        }
    }
    
    for(long long i = 2; i < segment; i++) {
        if(prime[i]) {
            allPrime[cnt++] = i;
        }
    }

    for(idx = 2; idx <= maxIdx; idx++) {
        memset(prime, true, segment * sizeof(bool));
        for(long long i = 0; i < cnt; i++) {
            if(allPrime[i] == 0) {
                break;
            }
            long long q = (idx - 1) * segment / allPrime[i];
            long long t = allPrime[i] * q;
            while(t < (idx - 1) * segment) {
                t += allPrime[i];
            }
            while(t < idx * segment) {
                prime[t % segment] = false;
                t += allPrime[i];
            }
        }

        for(long long i = 0; i < segment; i++) {
            if(prime[i]) {
                cnt++;
            }
        }
    }

    cout<<"Result "<<cnt<<endl;

    delete[] prime;
    delete[] allPrime;

    int wait = 0;
    cin>>wait;

    return 0; 
}
