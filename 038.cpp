/*
由于n>1，所以至少要有两个数，所以基数一定至多有4位，否则矛盾。所以考虑4位及其以下即可。
*/

#include <iostream>
#include <string>
#include <set>

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

bool pushSet(set<int>& s, int num) {
    while(num) {
        if(s.find(num % 10) != s.end()) {
            return false;
        }
        s.insert(num % 10);
        num /= 10;
    }
    return true;
}

string reverse(string str) {
    int n = str.size();
    if(n < 2) return str;
    for(int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - 1 - i]);
    }

    return str;
}

string itos(int n) {
    string res = "";
    if(n == 0) return "0";
    if(n < 0) {
        res = "-";
        res += itos(-n);
        return res;
    }
    while(n > 0) {
        res.append(1, '0' + n % 10);
        n /= 10;
    }
    
    
    return reverse(res);
}

int isValid(int k) {
    if(hasZeroDigit(k)) return -1;
    set<int> s;
    int n = 1;
    for(n = 1; n <= 9; n++) {
        if(hasZeroDigit(k * n) || !pushSet(s, k * n) || (s.size() > 9)) {
            return -1;
        }
        if(s.size() == 9) {
            string str = "";
            for(int i = 1; i <= n; i++) {
                str += itos(k * i);
            }
            int res = stoi(str);
            return res;
        }
    }
    return -1;
}

int main() {
    int N = 10000;

    int res = 0;
    for(int k = 1; k < N; k++) {
        int t = isValid(k);
        if(t != -1) {
            cout<<k<<" "<<t<<endl;
            res = max(res, t);
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
