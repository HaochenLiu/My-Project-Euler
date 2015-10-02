#include <set>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if(a == b) return a;
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b) * b);
}

int main() {
    long long res = 1;
    for(int i = 2; i <= 20; i++) {
        res = lcm(res, i);
        cout<<"i = "<<i<<" res = "<<res<<endl;
    }

    int wait = 0;
    cin>>wait;

    return 0; 
}
