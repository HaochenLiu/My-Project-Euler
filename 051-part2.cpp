/*
满足条件的4位数不存在。
考虑原数是5位数的情况：YYXXX, YXYXX, YXXYX, YXXXY, XYYXX, XYXYX, XYXXY, XXYYX, XXYXY, XXXYY。
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int getFiveDigit(int a, int b, int c, int d, int e) {
    return (10000 * a + 1000 * b + 100 * c + 10 * d + e);
}

int main() {
    int N = 100000;
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

    int Y1;
    int Y2;
    int X;

    /* YYXXX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 0; X <= 9; X++) {
                t = getFiveDigit(Y1, Y2, X, X, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(Y1, Y2, X, X, X)<<endl;
            }
        }
    }

    /* YXYXX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 0; X <= 9; X++) {
                t = getFiveDigit(Y1, X, Y2, X, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(Y1, X, Y2, X, X)<<endl;
            }
        }
    }

    /* YXXYX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 0; X <= 9; X++) {
                t = getFiveDigit(Y1, X, X, Y2, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(Y1, X, X, Y2, X)<<endl;
            }
        }
    }

    /* YXXXY */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 0; X <= 9; X++) {
                t = getFiveDigit(Y1, X, X, X, Y2);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(Y1, X, X, X, Y2)<<endl;
            }
        }
    }

    /* XYYXX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, Y1, Y2, X, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, Y1, Y2, X, X)<<endl;
            }
        }
    }

    /* XYXYX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, Y1, X, Y2, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, Y1, X, Y2, X)<<endl;
            }
        }
    }

    /* XYXXY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, Y1, X, X, Y2);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, Y1, X, X, Y2)<<endl;
            }
        }
    }

    /* XXYYX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, X, Y1, Y2, X);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, X, Y1, Y2, X)<<endl;
            }
        }
    }

    /* XXYXY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, X, Y1, X, Y2);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, X, Y1, X, Y2)<<endl;
            }
        }
    }

    /* XXXYY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            int cnt = 0;
            int t;
            for(X = 1; X <= 9; X++) {
                t = getFiveDigit(X, X, X, Y1, Y2);
                if(prime[t]) {
                    cnt++;
                }
            }
            if(cnt >= 8) {
                cout<<"Y1 "<<Y1<<"Y2 "<<Y2<<" X "<<X<<" num "<<getFiveDigit(X, X, X, Y1, Y2)<<endl;
            }
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
