/*
http://www.mathblog.dk/project-euler-73-sorted-reduced-proper-fractions/
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

long long gcd(long long a, long long b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a = 3;
    int b = 2;
    int limit = 12000;
    int result = 0;
 
    for(int d = 5; d <= limit; d++) {
        for(int n = d / a + 1; n < (d - 1) / b + 1; n++) {
            if(gcd(n, d) == 1) {
                result++;
            }
        }
    }
    cout<<result<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
