/*
n如果选8或者9，必然被3整除。所以n最大为7。
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int digitCnt(int n) {
    int res = 0;
    while(n) {
        res++;
        n /= 10;
    }
    return res;
}

bool isPandigital(int n) {
    int digit = digitCnt(n);
    unordered_map<int, int> m;
    for(int i = 1; i <= digit; i++) {
        m[i] = 1;
    }
    for(int i = 1; i <= digit; i++) {
        if(m.find(n % 10) == m.end()) {
            return false;
        } else {
            m[n % 10]--;
            if(m[n % 10] != 0) {
                return false;
            }
            n /= 10;
        }
    }
    return true;
}

int main() {
    int N = 10000000;
    bool* prime = new bool[N];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    for(int i = 7652413; i >= 7652413; i--) {
        if(i % 1000 == 0) {
            cout<<i<<endl;
        }
        if(prime[i] && isPandigital(i)) {
            cout<<"Result "<<i<<endl;
            break;
        }
    }
    cout<<"Out"<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
