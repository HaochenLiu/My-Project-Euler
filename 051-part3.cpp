/*
满足条件的5位数不存在。
考虑原数是6位数的情况：
YYYXXX, YYXYXX, YYXXYX, YYXXXY
YXYYXX, YXYXYX, YXYXXY
YXXYYX, YXXYXY
YXXXYY
XYYYXX, XYYXYX, XYYXXY
XYXYYX, XYXYXY
XYXXYY
XXYYYX, XXYYXY
XXYXYY
XXXYYY
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

int getSixDigit(int a, int b, int c, int d, int e, int f) {
    return (100000 * a + 10000 * b + 1000 * c + 100 * d + 10 * e + f);
}

int main() {
    int N = 1000000;
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
    int Y3;
    int X;

    /* YYYXXX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, Y2, Y3, X, X, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, Y2, Y3, X, X, X)<<endl;
                }
            }
        }
    }

    /* YYXYXX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, Y2, X, Y3, X, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, Y2, X, Y3, X, X)<<endl;
                }
            }
        }
    }

    /* YYXXYX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, Y2, X, X, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, Y2, X, X, Y3, X)<<endl;
                }
            }
        }
    }

    /* YYXXXY */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, Y2, X, X, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, Y2, X, X, X, Y3)<<endl;
                }
            }
        }
    }

    /* YXYYXX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, Y2, Y3, X, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, Y2, Y3, X, X)<<endl;
                }
            }
        }
    }

    /* YXYXYX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, Y2, X, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, Y2, X, Y3, X)<<endl;
                }
            }
        }
    }

    /* YXYXXY */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, Y2, X, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, Y2, X, X, Y3)<<endl;
                }
            }
        }
    }

    /* YXXYYX */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, X, Y2, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, X, Y2, Y3, X)<<endl;
                }
            }
        }
    }

    /* YXXYXY */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, X, Y2, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, X, Y2, X, Y3)<<endl;
                }
            }
        }
    }

    /* YXXXYY */
    for(Y1 = 1; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 0; X <= 9; X++) {
                    t = getSixDigit(Y1, X, X, X, Y2, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(Y1, X, X, X, Y2, Y3)<<endl;
                }
            }
        }
    }

    /* XYYYXX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, Y2, Y3, X, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, Y2, Y3, X, X)<<endl;
                }
            }
        }
    }

    /* XYYXYX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, Y2, X, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, Y2, X, Y3, X)<<endl;
                }
            }
        }
    }

    /* XYYXXY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, Y2, X, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, Y2, X, X, Y3)<<endl;
                }
            }
        }
    }

    /* XYXYYX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, X, Y2, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, X, Y2, Y3, X)<<endl;
                }
            }
        }
    }

    /* XYXYXY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, X, Y2, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, X, Y2, X, Y3)<<endl;
                }
            }
        }
    }

    /* XYXXYY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, Y1, X, X, Y2, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, Y1, X, X, Y2, Y3)<<endl;
                }
            }
        }
    }

    /* XXYYYX */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, X, Y1, Y2, Y3, X);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, X, Y1, Y2, Y3, X)<<endl;
                }
            }
        }
    }

    /* XXYYXY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, X, Y1, Y2, X, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, X, Y1, Y2, X, Y3)<<endl;
                }
            }
        }
    }

    /* XXYXYY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, X, Y1, X, Y2, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, X, Y1, X, Y2, Y3)<<endl;
                }
            }
        }
    }

    /* XXXYYY */
    for(Y1 = 0; Y1 <= 9; Y1++) {
        for(Y2 = 0; Y2 <= 9; Y2++) {
            for(Y3 = 0; Y3 <= 9; Y3++) {
                int cnt = 0;
                int t;
                for(X = 1; X <= 9; X++) {
                    t = getSixDigit(X, X, X, Y1, Y2, Y3);
                    if(prime[t]) {
                        cnt++;
                    }
                }
                if(cnt >= 8) {
                    X = 1;
                    cout<<"Y1 "<<Y1<<" Y2 "<<Y2<<" Y3 "<<Y3<<" X "<<X<<" num "<<getSixDigit(X, X, X, Y1, Y2, Y3)<<endl;
                }
            }
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
