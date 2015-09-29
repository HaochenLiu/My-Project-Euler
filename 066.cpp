/*
参考64，65题。
https://zh.wikipedia.org/wiki/%E4%BD%A9%E5%B0%94%E6%96%B9%E7%A8%8B
*/


#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

const int bigNumDigit = 100;

struct bignum {
    int a[bigNumDigit];
    int point; 
    bool minus;
};

bignum operator/(bignum x, bignum y);
bignum operator/(bignum x, int y);
bool operator>=(bignum x, bignum y);
bool operator<=(bignum x, bignum y);
bool operator==(bignum x, bignum y);
bool operator==(bignum x, int y);
bool operator==(int x, bignum y);
bool operator>(bignum x, bignum y);
bool operator<(bignum x, bignum y);
bool operator<(bignum x, int y);
bool operator<(int x, bignum y);
bignum operator+(bignum x, bignum y);
bignum operator-(bignum x, bignum y);
bignum operator-(bignum x, int y);
bignum operator-(int x, bignum y);
bignum operator&(bignum x, int y);
void checkZeroSign(bignum& x);
bignum max(bignum x, bignum y);
bignum min(bignum x, bignum y);
bignum square(bignum x);
bignum abs(bignum x);
bignum lltobignum(long long n);
bignum stobignum(string str);
string bignumtos(bignum num);
int getDigitCnt(bignum num);
int getDigitSum(bignum num);

bignum stobignum(string str) {
    if(str.empty() || str == "0") return lltobignum(0);
    bignum res = lltobignum(0);
    if(str[0] == '-') {
        res.minus = true;
        str.erase(0);
    }
    int n = str.size();
    for(int i = n - 1; i >= 0; i--) {
        res.a[n - 1 - i] = str[i] - '0';
    }
    checkZeroSign(res);
    return res;
}

string bignumtos(bignum num) {
    if(num == 0) return "0";
    string res = "";
    if(num.minus) {
        res = "-";
    }
    int i;
    bool flag = false;
    for(i = bigNumDigit - 1; i >= 0; i--) {
        if(num.a[i] != 0) {
            flag = true;
        }
        if(flag) {
            res.append(1, num.a[i] + '0');
        }
    }
    return res;
}

bignum lltobignum(long long n) {
    bignum num;
    memset(num.a, 0, sizeof(num.a));
    num.point = 0;
    num.minus = false;
    if(n == 0) {
        return num;
    } else if(n < 0) {
        num.minus = true;
        n = -n;
    }
    for(int i = 0; i < bigNumDigit; i++) {
        num.a[i] = n % 10;
        n /= 10;
        if(n == 0) {
            break;
        }
    }
    return num;
}

bignum operator+(bignum x, bignum y) {
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

    bignum z = lltobignum(0);
    if(x.minus == y.minus) {
        for(int i = 0; i < bigNumDigit; i++) {
            z.a[i] = x.a[i] + y.a[i];
        }
        z.point = x.point;
        z.minus = x.minus;

        int carry = 0;
        for(int i = 0; i < bigNumDigit; i++) {
            z.a[i] = z.a[i] + carry;
            carry = z.a[i] / 10;
            z.a[i] %= 10;
        }
        checkZeroSign(z);
        return z;
    } else {
        if(abs(x) == abs(y)) {
            return lltobignum(0);
        } else if(abs(x) > abs(y)) {
            bignum z = abs(x) - abs(y);
            z.point = x.point;
            z.minus = x.minus;
            return z;
        } else {
            bignum z = abs(y) - abs(x);
            z.point = y.point;
            z.minus = y.minus;
            return z;
        }
    }

    return z;
} 

bignum operator+(bignum x, int y) {
    return (x + lltobignum(y));
}

bignum operator+(int x, bignum y) {
    return (lltobignum(x) + y);
}

bignum operator-(bignum x, bignum y) {
    if(x == lltobignum(0)) return y;
    if(x == y) return lltobignum(0);
    if(x.minus != y.minus) {
        bignum z = abs(x) + abs(y);
        z.minus = x.minus;
        return z;
    } else {
        if(abs(x) == abs(y)) {
            return lltobignum(0);
        } else if(abs(x) > abs(y)) {
            int digit = getDigitCnt(y) - 1;
            for(int i = 0; i <= digit; i++) {
                if(x.a[i] >= y.a[i]) {
                    x.a[i] = x.a[i] - y.a[i];
                } else {
                    int j;
                    for(j = i + 1; j < bigNumDigit; j++) {
                        if(x.a[j] != 0) {
                            break;
                        } else {
                            x.a[j] = 9;
                        }
                    }
                    x.a[j] = x.a[j] - 1;
                    x.a[i] = x.a[i] + 10 - y.a[i];
                }
            }
            return x;
        } else {
            int digit = getDigitCnt(y) - 1;
            for(int i = 0; i <= digit; i++) {
                if(y.a[i] >= x.a[i]) {
                    y.a[i] = y.a[i] - x.a[i];
                } else {
                    int j;
                    for(j = i + 1; j < bigNumDigit; j++) {
                        if(y.a[j] != 0) {
                            break;
                        } else {
                            y.a[j] = 9;
                        }
                    }
                    y.a[j] = y.a[j] - 1;
                    y.a[i] = y.a[i] + 10 - x.a[i];
                }
            }
            if(y.minus) {
                y.minus = false;
            } else {
                y.minus = true;
            }
            return y;
        }
    }
}

bignum operator-(bignum x, int y) {
    return (x - lltobignum(y));
}

bignum operator-(int x, bignum y) {
    return (lltobignum(x) - y);
}

bignum operator*(bignum x, bignum y) {
    bignum z = lltobignum(0);

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

bignum operator*(bignum x, int y) {
    if(y == 0) return lltobignum(0);
    bignum z = lltobignum(0);
    if(y < 0) {
        if(x.minus) {
            z.minus = false;
        } else {
            z.minus = true;
        }
    }

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

bignum operator*(int x, bignum y) {
    return (y * x);
}

bignum operator/(bignum x, bignum y) {
    if(y == lltobignum(0)) return lltobignum(0);
    if(y == lltobignum(1)) return x;
    if(x < y) return lltobignum(0);
    if(x == y) return lltobignum(1);
    int digit = getDigitCnt(y) - 1;
    if(y == ((lltobignum(10) & digit))) {
        for(int i = 0; i + digit < bigNumDigit; i++) {
            x.a[i] = x.a[i + digit];
        }
        return x;
    }

    bignum res = lltobignum(0);
    while(x >= y) {
        bignum small = lltobignum(1);
        bignum large = lltobignum(10);
        while(x >= large * y) {
            large = (large * 10);
            small = (small * 10);
        }
        res = res + small;
        x = x - (small * y);
    }

    return res;
}

bignum operator/(bignum x, int y) {
    return (x / lltobignum(y));
}

bool operator>=(bignum x, bignum y) {
    return (x > y) || (x == y);
}

bool operator<=(bignum x, bignum y) {
    return (x < y) || (x == y);
}

bool operator>(bignum x, bignum y) {
    if(!x.minus && y.minus) return true;
    if(x.minus && !y.minus) return false;
    if(x.minus && y.minus) return(abs(x) < abs(y));
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

bool operator<(bignum x, int y) {
    return (x < lltobignum(y));
}

bool operator<(int x, bignum y) {
    return (lltobignum(x) < y);
}

bool operator==(bignum x, bignum y) {
    checkZeroSign(x);
    checkZeroSign(y);
    if(x.point != y.point) return false;
    if(x.minus != y.minus) return false;
    for(int i = 0; i < bigNumDigit; i++) {
        if(x.a[i] != y.a[i]) {
            return false;
        }
    }
    return true;
}

bool operator==(bignum x, int y) {
    return (x == lltobignum(y));
}

bool operator==(int x, bignum y) {
    return (lltobignum(x) == y);
}

void checkZeroSign(bignum& x) {
    for(int i = 0; i < bigNumDigit; i++) {
        if(x.a[i] != 0) {
            return;
        }
    }
    x.minus = false;
    return;
}

bignum square(bignum x) {
    return x * x;
}

bignum abs(bignum x) {
    x.minus = false;
    return x;
}

/* x^y */
bignum operator&(bignum x, int y) {
    if(y == 0) return lltobignum(1);
    if(y == 1) return x;
    if((y & 1) == 0) {
        return square(x & (y >> 1));
    } else {
        return x * square(x & (y >> 1));
    }
}

int getDigitSum(bignum num) {
    int res = 0;
    for(int i = 0; i < bigNumDigit; i++) {
        res += num.a[i];
    }
    return res;
}

int getDigitCnt(bignum num) {
    int i = 0;
    for(i = bigNumDigit - 1; i >= 0; i--) {
        if(num.a[i] != 0) {
            return (i + 1);
        }
    }
    return 0;
}

bignum max(bignum x, bignum y) {
    if(x > y) return x;
    return y;
}

bignum min(bignum x, bignum y) {
    if(x > y) return y;
    return x;
}

bool isSquare(bignum n) {
    if(n == lltobignum(0)) return true;
    if(n == lltobignum(1)) return true;
    int digit = getDigitCnt(n);
    bignum low = lltobignum(1);
    bignum ten = lltobignum(10);
    bignum high = (ten & (digit + 1) / 2);

    while(low <= high) {
        bignum mid = (low + high) / 2;
        bignum t = mid * mid;
        if(t == n) {
            return true;
        }
        if(t < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

long long gcd(long long a, long long b) {
    if(a == b) return a;
    if(a > b) return gcd(b, a);
    if(b % a == 0) return a;
    return gcd(a, b % a);
}

bool isSquare(int n) {
    int t = (int)sqrt((double)n);
    return (t * t == n);
}

bignum getX(int D) {
    vector<int> contFrac;
    int srn = (int)sqrt((double)D);
    vector<int> prev;
    prev.resize(4);
    prev[0] = srn;
    prev[1] = 1;
    prev[2] = srn;
    prev[3] = D - srn * srn;
    contFrac.push_back(srn);

    while(true) {
        vector<int> cur;
        cur.resize(4);
        cur[0] = (prev[1] * srn + prev[2]) / prev[3];
        cur[1] = prev[1] * prev[3];
        cur[2] = (cur[0] * prev[3] - prev[2]) * prev[3];
        cur[3] = prev[1] * prev[1] * D - (prev[2] - cur[0] * prev[3]) * (prev[2] - cur[0] * prev[3]);
        int g = gcd(cur[1], cur[2]);
        g = gcd(g, cur[3]);
        cur[1] /= g;
        cur[2] /= g;
        cur[3] /= g;
        contFrac.push_back(cur[0]);
        prev = cur;
        bignum n = lltobignum(1);
        bignum d = lltobignum(contFrac[contFrac.size() - 1]);
        for(int i = contFrac.size() - 2; i >= 0; i--) {
            n = n + (contFrac[i] * d);
            swap(n, d);
        }
        if(((d * d) - (D * n * n)) == 1) {
            return d;
        }
    }
}

int main() {
    bignum maxVal = lltobignum(0);
    int maxIdx = 0;
    int N = 1000;
    for(int i = 2; i <= N; i++) {
        if(isSquare(i)) continue;
        bignum X = getX(i);
        cout<<"i "<<i<<" X "<<bignumtos(X)<<endl;
        if(maxVal < X) {
            maxVal = X;
            maxIdx = i;
        }
    }

    cout<<"maxIdx "<<maxIdx<<" maxVal "<<bignumtos(maxVal)<<endl;

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
