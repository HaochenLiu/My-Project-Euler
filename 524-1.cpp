/*
8916100448256
24 28 29 30 31 32 33 35 36 43 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n = 1;
    for(int i = 1; i <= 12; i++) {
        n *= 12;
    }
    cout<<n<<endl;

    long long res = 1;
    for(int i = 0; i < 64; i++) {
        long long t = res<<i;
        if(n & t) {
            cout<<i<<" ";
        }
    }
    cout<<endl;

    int wait;
    cin>>wait;

    return 0;
}
