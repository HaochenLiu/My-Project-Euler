/*
乘积不可能为5位数，甚至更高。
乘积不可能为3位数，甚至更低。
所以乘积，只考虑4位数的就可以了。
可能是
1位数*4位数=4位数
2位数*3位数=4位数
*/

#include <iostream>
#include <set>

using namespace std;

int getDigit(set<int>& s, int n) {
    int res = 0;
    while(n) {
        if(n % 10 == 0) {
            return -1;
        }
        s.insert(n % 10);
        n /= 10;
        res++;
    }

    return res;
}

bool isValid(int product, int i, int j) {
    set<int> s;
    int dp = getDigit(s, product);
    int di = getDigit(s, i);
    int dj = getDigit(s, j);
    if(dp == -1 || di == -1 || dj == -1) return false;
    if(getDigit(s, product) + getDigit(s, i) + getDigit(s, j) != 9) return false;

    return (s.size() == 9);
}

int main() {
    int res = 0;
    for(int product = 1234; product <= 9876; product++) {
        for(int i = 2; i <= (int)sqrt((double)product); i++) {
            if(product % i == 0) {
                int j = product / i;
                if(isValid(product, i, j)) {
                    res += product;
                    cout<<product<<" = "<<i<<" * "<<j<<endl;
                    break;
                }
            }
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
