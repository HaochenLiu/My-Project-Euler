#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    int n1 = 20;
    int n2 = 20;
    long long res = 1;
    for(int i = 1; i <= n1; i++) {
        res *= (i + n2);
        res /= i;
    }

    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
