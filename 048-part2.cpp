/*
加入PowerLastDigit功能，适用于N=1000。
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>

using namespace std;

const int bigNumDigit = 30;

struct bignum {
    int a[bigNumDigit];
    int point; 
} num; 

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

bignum keepLastDigit(bignum x, int last) {
    for(int i = last; i < bigNumDigit; i++) {
        x.a[i] = 0;
    }
    return x;
}

bignum square(bignum x) {
    return x * x;
}

bignum powerLastDigit(bignum x, int y, int last) {
    x = keepLastDigit(x, last);
    if(y == 1) return x;
    if((y & 1) == 0) {
        x = powerLastDigit(x, y >> 1, last);
        x = square(x);
        x = keepLastDigit(x, last);
        return x;
    } else {
        bignum t = powerLastDigit(x, y >> 1, last);
        t = square(t);
        t = keepLastDigit(t, last);
        x = x * t;
        x = keepLastDigit(x, last);
        return x;
    }
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

void printNum(bignum num) {
    for(int i = 0; i < bigNumDigit; i++) {
        cout<<num.a[i];
    }
    cout<<endl;
    cout<<"num.point "<<num.point<<endl;

    return;
}

int main() {
    bignum sum;
    sum.point = 0;
    memset(sum.a, 0, sizeof(sum.a));
    int N = 1000;
    int last = 10;
    for(int i = 1; i < N; i++) {
        bignum num;
        num.point = 0;
        memset(num.a, 0, sizeof(num.a));
        num.a[0] = i % 10;
        num.a[1] = i / 10 % 10;
        num.a[2] = i / 100;
        num = powerLastDigit(num, i, last);
        sum = sum + num;
    }

    for(int i = 9; i >= 0; i--) {
        cout<<sum.a[i];
    }
    cout<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
