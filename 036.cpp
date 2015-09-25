#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int reverse(int n) {
    if(n <= 0) return 0;
    int res = 0;
    while(n > 0) {
        res *= 10;
        res += n % 10;
        n /= 10;
    }

    return res;
}

bool isPalindrome(int n) {
    if(n < 0) return false;
    return (n == reverse(n));
}

bool isPalindrome(string str) {
    int n = str.size();
    if(n < 2) return true;
    for(int i = 0; i < n; i++) {
        if(str[i] != str[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool isBinParlindrom(int n) {
    bitset<32> b(n);
    string str = b.to_string();
    while(str[0] == '0') {
        str.erase(str.begin());
    }
    return isPalindrome(str);
}

bool isValid(int n) {
    return (isPalindrome(n) && isBinParlindrom(n));
}

int main() {
    int N = 1000000;

    int res = 0;
    for(int i = 1; i < N; i++) {
        if(isValid(i)) {
            cout<<i<<endl;
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
