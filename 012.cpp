/*
http://math.stackexchange.com/questions/295465/how-many-positive-integers-are-factors-of-a-given-number
*/

#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

int getFactorNum(int n) {
    if(n == 1) return 1;
    unordered_map<int, int> m;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            m[i]++;
            n /= i;
            i--;
        }
    }

    int res = 1;
    unordered_map<int, int>::iterator it = m.begin();
    while(it != m.end()) {
        res *= (it->second + 1);
        it++;
    }

    return res;
}

int tri(int n) {
    return (n * (n + 1) /2 );
}

int main() {
    for(int i = 1; i < 20000; i++) {
        cout<<i<<" "<<getFactorNum(tri(i))<<endl;
        if(getFactorNum(tri(i)) > 500) {
            cout<<i<<" "<<tri(i)<<" "<<getFactorNum(tri(i))<<endl;
            break;
        }
    }

    int wait = 0;
    cin>>wait;

    return 0; 
}
