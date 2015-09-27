/*
得到最小值。
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

long long N = 10000;

long long cube(long long n) {
    return (n * n * n);
}

string lltostr(long long n) {
    if(n == 0) return "0";
    string res = "";
    while(n) {
        res.append(1, '0' + n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    long long minVal = 0;
    for(long long i = 1; i < N; i++) {
        string t = lltostr(cube(i));
        sort(t.begin(), t.end());
        if(t == "012334566789" || t == "012334556789") {
            if(minVal == 0 || minVal > cube(i)) {
                minVal = cube(i);
            }
        }
    }
    
    cout<<"Result "<<minVal<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
