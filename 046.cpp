#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int square(int n) {
    return (n * n);
}

bool isSquare(int n) {
    if(n < 0) return false;
    if(n < 2) return true;
    int t = (int)sqrt((double)n);
    return (t * t == n);
}

int main() {
    int N = 10001;
    bool* prime = new bool[N];
    memset(prime, true, sizeof(bool) * N);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    bool* oddComposite = new bool[N];
    memset(oddComposite, false, sizeof(bool) * N);
    for(int i = 9; i < N; i++) {
        if((i % 2 == 1) && !prime[i]) {
            oddComposite[i] = true;
        }
    }

    for(int i = 9; i < N; i++) {
        if(oddComposite[i]) {
            bool flag = false;
            for(int j = 1; j < i; j++) {
                if(2 * square(j) >= i) {
                    break;
                }
                if(prime[i - 2 * square(j)]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout<<i<<endl;
                break;
            }
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
