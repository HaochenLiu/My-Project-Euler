/*
n位整数的下限为10^(n-1)。
位数的五次方之和的上限为n*(9^5)。
取n=7，得出矛盾。
所以只考虑2位数——6位数的可能性即可。
*/

#include <iostream>

using namespace std;

int fifthPower(int n) {
    return (n * n * n * n * n);
}

int getFifthPowerSum(int n) {
    int res = 0;
    while(n) {
        res += fifthPower(n % 10);
        n /= 10;
    }
    return res;
}

bool isValid(int n) {
    return (n == getFifthPowerSum(n));
}

int main() {
    int res = 0;
    for(int i = 2; i < 1000000; i++) {
        if(isValid(i)) {
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
