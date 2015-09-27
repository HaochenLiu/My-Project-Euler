#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

const int bigNumDigit = 200;

struct bignum {
    int a[bigNumDigit];
    int point; 
};

bignum operator+(bignum x, bignum y) {
    bignum z;
    memset(z.a, 0, sizeof(z.a)); 
    if(x.point < y.point) {
        int diff = y.point - x.point;
        x.point = y.point;
        for(int i = bigNumDigit - 1 - diff; i >= 0; i--) {
            x.a[i + diff] = x.a[i];
        }
        for(int i = diff - 1; i >= 0; i--) {
            x.a[i] = 0;
        }
    } else if(y.point < x.point) {
        int diff = x.point - y.point;
        y.point = x.point;
        for(int i = bigNumDigit - 1 - diff; i >= 0; i--) {
            y.a[i + diff] = y.a[i];
        }
        for(int i = diff - 1; i >= 0; i--) {
            y.a[i] = 0;
        }
    }

    for(int i = 0; i < bigNumDigit; i++) {
        z.a[i] = x.a[i] + y.a[i];
    }
    z.point = x.point;

    int carry = 0;

    for(int i = 0; i < bigNumDigit; i++) {
        z.a[i] = z.a[i] + carry;
        carry = z.a[i] / 10;
        z.a[i] %= 10;
    }

    return z;
} 

bignum operator*(bignum x, int y) {
    bignum z;
    z.point = x.point;
    memset(z.a, 0, sizeof(z.a)); 

    for(int i = 0; i < bigNumDigit; i++) {
        z.a[i] = x.a[i] * y;
    }

    int carry = 0;

    for(int i = 0; i < bigNumDigit; i++) {
        z.a[i] = z.a[i] + carry;
        carry = z.a[i] / 10;
        z.a[i] %= 10;
    }

    return z;
} 

bignum operator*(bignum x, bignum y) {
    bignum z;
    z.point = x.point + y.point;
    memset(z.a, 0, sizeof(z.a)); 

    for(int i = 0; i < bigNumDigit; i++) {
        for(int j = 0; j <= i; j++) {
            z.a[i] += x.a[j] * y.a[i - j];
        }
    }

    int carry = 0;

    for(int i = 0; i < bigNumDigit; i++) {
        z.a[i] = z.a[i] + carry;
        carry = z.a[i] / 10;
        z.a[i] %= 10;
    }

    return z;
} 

bool operator>(bignum x, bignum y) {
    if(x.point < y.point) {
        int diff = y.point - x.point;
        x.point = y.point;
        for(int i = bigNumDigit - 1 - diff; i >= 0; i--) {
            x.a[i + diff] = x.a[i];
        }
        for(int i = diff - 1; i >= 0; i--) {
            x.a[i] = 0;
        }
    } else if(y.point < x.point) {
        int diff = x.point - y.point;
        y.point = x.point;
        for(int i = bigNumDigit - 1 - diff; i >= 0; i--) {
            y.a[i + diff] = y.a[i];
        }
        for(int i = diff - 1; i >= 0; i--) {
            y.a[i] = 0;
        }
    }

    for(int i = bigNumDigit - 1; i >= 0; i--) {
        if(x.a[i] > y.a[i]) {
            return true;
        } else if(x.a[i] < y.a[i]) {
            return false;
        }
    }

    return false;
} 

bool operator<(bignum x, bignum y) {
    return (y > x);
}

bignum square(bignum x) {
    return x * x;
}

/*
x^y
*/
bignum operator&(bignum x,int y) {
    if(y == 1) return x;
    if((y & 1) == 0) {
        return square(x & (y >> 1));
    } else {
        return x * square(x & (y >> 1));
    }
}

string bignumtos(bignum num) {
    string res = "";
    int i = bigNumDigit - 1;
    bool flag = false;
    for(i = bigNumDigit - 1; i >= 0; i--) {
        if(num.a[i] != 0) {
            flag = true;
        }
        if(flag) {
            res.append(1, num.a[i] + '0');
        }
    }
    if(flag) {
        return res;
    } else {
        return "0";
    }
}

bignum stobignum(string str) {
    bignum res;
    memset(res.a, 0, sizeof(res.a));
    res.point = 0;
    int n = str.size();
    for(int i = n - 1; i >= 0; i--) {
        res.a[n - 1 - i] = str[i] - '0';
    }
    return res;
}

bignum lltobignum(long long n) {
    bignum num;
    memset(num.a, 0, sizeof(num.a));
    num.point = 0;
    for(int i = 0; i < bigNumDigit; i++) {
        num.a[i] = n % 10;
        n /= 10;
        if(n == 0) {
            break;
        }
    }
    return num;
}

int getDigitSum(bignum num) {
    int res = 0;
    for(int i = 0; i < bigNumDigit; i++) {
        res += num.a[i];
    }
    return res;
}

int N = 100;

int main() {
    int res = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            bignum num = lltobignum(i);
            num = (num & j);
            res = max(res, getDigitSum(num));
        }
    }
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
