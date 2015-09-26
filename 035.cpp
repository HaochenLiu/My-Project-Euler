#include <iostream>
#include <vector>
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

int rotateRight(int n) {
    int digit = digitCnt(n);
    int lastDigit = n % 10;
    int beginDigits = n / 10;
    return (lastDigit * power(10, digit - 1) + beginDigits);
}

bool isValid(bool* prime, int n) {
    if(!prime[n] || hasZeroDigit(n)) {
        return false;
    }
    int next = rotateRight(n);
    while(next != n) {
        if(!prime[next]) {
            return false;
        }
        next = rotateRight(next);
    }
    return true;
}

int main() {
    int N = 1000001;
    bool* prime = new bool[N];
    memset(prime, true, sizeof(bool) * N);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    int res = 0;
    for(int i = 2; i < N; i++) {
        if(isValid(prime, i)) {
            cout<<i<<endl;
            res++;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
