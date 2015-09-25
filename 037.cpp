#include <iostream>

using namespace std;

bool hasZeroDigit(int n) {
    if(n == 0) return true;
    while(n) {
        if(n % 10 == 0) {
            return true;
        }
        n /= 10;
    }

    return false;
}

int digitCnt(int n) {
    int res = 0;

    while(n) {
        res++;
        n /= 10;
    }
    
    return res;
}

int square(int x) {
    return (x * x);
}

int power(int x, int y) {
    if(x == 0) return 0;
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y % 2 == 0) return square(power(x, y / 2));
    return (x * square(power(x, y / 2)));
}

int truncateLeft(int n) {
    int digit = digitCnt(n);
    return (n % power(10, digit - 1));
}

int truncateRight(int n) {
    return (n / 10);
}

bool isValid(bool* prime, int n) {
    if(!prime[n] || hasZeroDigit(n)) {
        return false;
    }

    int nextLeft = truncateLeft(n);
    while(nextLeft != 0) {
        if(!prime[nextLeft]) {
            return false;
        }
        nextLeft = truncateLeft(nextLeft);
    }

    int nextRight = truncateRight(n);
    while(nextRight != 0) {
        if(!prime[nextRight]) {
            return false;
        }
        nextRight = truncateRight(nextRight);
    }

    return true;
}

int main() {
    int N = 1000001;
    bool* prime = new bool[N];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    int res = 0;
    for(int i = 11; i < N; i++) {
        if(isValid(prime, i)) {
            cout<<i<<endl;
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
