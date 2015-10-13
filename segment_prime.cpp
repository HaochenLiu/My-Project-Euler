/*
为了省空间也是拼了。
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
#include <queue>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
    int segment = 10000000;
    int idx = 1;
    int maxIdx = 100;
    int cnt = 0;
    int maxCnt = 6 * segment;
    int* allPrime = new int[maxCnt];
    memset(allPrime, 0, maxCnt * sizeof(int));
    bool* prime = new bool[segment];
    memset(prime, true, segment * sizeof(bool));

    for(int i = 2; i <= (int)sqrt((double)segment); i++) {
        for(int j = 2 * i; j < segment; j += i) {
            prime[j] = false;
        }
    }
    
    for(int i = 2; i < segment; i++) {
        if(prime[i]) {
            allPrime[cnt++] = i;
        }
    }
    cout<<"idx "<<idx<<" cnt "<<cnt<<endl;

    for(idx = 2; idx <= maxIdx; idx++) {
        memset(prime, true, segment * sizeof(bool));
        for(int i = 0; i < cnt; i++) {
            int q = (idx - 1) * segment / allPrime[i];
            int t = allPrime[i] * q;
            while(t < (idx - 1) * segment) {
                t += allPrime[i];
            }
            while(t < idx * segment) {
                prime[t % segment] = false;
                t += allPrime[i];
            }
        }

        for(int i = 0; i < segment; i++) {
            if(prime[i]) {
                allPrime[cnt++] = (idx - 1) * segment + i;
            }
        }
        cout<<"idx "<<idx<<" cnt "<<cnt<<endl;
    }

    cout<<"Result "<<cnt<<endl;

    delete[] prime;
    delete[] allPrime;

    int wait = 0;
    cin>>wait;

    return 0; 
}
