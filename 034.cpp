/*
n位整数的下限为10^(n-1)。
位数的阶乘之和的上限为n*(9!)。
取n=8，得出矛盾。
所以只考虑至多7位数的可能性即可。
n=7时，上限为(9!)*7=2540160。
*/

#include <iostream>
#include <vector>

using namespace std;

int getFacSum(vector<int>& fac, int n) {
    int res = 0;
    while(n) {
        res += fac[n % 10];
        n /= 10;
    }

    return res;
}

int main() {
    int n = 10;
    vector<int> fac(n, 0);
    fac[0] = 1;
    for(int i = 1; i < n; i++) {
        fac[i] = fac[i - 1] * i;
    }

    int res = 0;
    for(int i = 3; i <= 2540160; i++) {
        if(i == getFacSum(fac, i)) {
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
