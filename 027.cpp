/*
Let n = 0, we know b has to be positive.
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int func(int n, int a, int b) {
    return (n * n + a * n + b);
}

int main() {
    int N = 200001;
    vector<bool> prime(N, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    int limit = 1000;
    int maxCnt = 39;
    int product = 41;
    for(int a = 1 - limit; a < limit; a++) {
        for(int b = 2; b < limit; b++) {
            int n = 0;
            while(true) {
                if(func(n, a, b) <= 0) {
                    break;
                } else if(func(n, a, b) >= N) {
                    cout<<"too big"<<endl;
                    return 0;
                } else if(!prime[func(n, a, b)]) {
                    break;
                } else {
                    n++;
                }
            }
            n--;

            if(n > maxCnt) {
                maxCnt = n;
                product = a * b;
                cout<<"a "<<a<<endl;
                cout<<"b "<<b<<endl;
                cout<<"n "<<n<<endl;
                cout<<"product "<<product<<endl;
            }
        }
    }

    cout<<product<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
