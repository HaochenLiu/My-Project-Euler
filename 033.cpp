#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if(a == b) return a;
    if(a > b) return gcd(b, a);
    if(b % a == 0) return a;
    return gcd(a, b % a);
}

int main() {
    int res = 0;
    int n = 1;
    int d = 1;
    int a[2];
    int b[2];
    for(int i = 11; i < 99; i++) {
        if(i % 10 == 0) {
            continue;
        }
        a[0] = i % 10;
        a[1] = i / 10;
        if(a[0] == a[1]) {
            continue;
        }
        for(int j = i + 1; j < 99; j++) {
            if(j % 10 == 0) {
                continue;
            }
            b[0] = j % 10;
            b[1] = j / 10;
            if(b[0] == b[1]) {
                continue;
            }
            set<int> s;
            s.insert(a[0]);
            s.insert(a[1]);
            s.insert(b[0]);
            s.insert(b[1]);
            if(s.size() == 4) {
                continue;
            }
            if(a[0] == b[0]) {
                if(a[1] * j == b[1] * i) {
                    n *= a[1];
                    d *= b[1];
                    cout<<i<<"/"<<j<<endl;
                }
            } else if(a[0] == b[1]) {
                if(a[1] * j == b[0] * i) {
                    n *= a[1];
                    d *= b[0];
                    cout<<i<<"/"<<j<<endl;
                }
            } else if(a[1] == b[0]) {
                if(a[0] * j == b[1] * i) {
                    n *= a[0];
                    d *= b[1];
                    cout<<i<<"/"<<j<<endl;
                }
            } else if(a[1] == b[1]) {
                if(a[0] * j == b[0] * i) {
                    n *= a[0];
                    d *= b[0];
                    cout<<i<<"/"<<j<<endl;
                }
            }
        }
    }

    int g = gcd(n, d);
    n /= g;
    d /= g;
    cout<<n<<endl;
    cout<<d<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
