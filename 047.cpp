#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

int getPrimeFactorNum(int n) {
    if(n == 1) return 1;
    unordered_map<int, int> m;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            m[i]++;
            n /= i;
            i--;
        }
    }

    return (m.size());
}

int main() {
    int N = 1000000;
    int n = 4;
    for(int i = 1; i < N; i++) {
        if(getPrimeFactorNum(i) == n
        && getPrimeFactorNum(i + 1) == n
        && getPrimeFactorNum(i + 2) == n
        && getPrimeFactorNum(i + 3) == n) {
            cout<<i<<endl;
            break;
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
