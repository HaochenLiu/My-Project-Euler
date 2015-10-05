/*
https://en.wikipedia.org/wiki/Euler%27s_totient_function
http://www.algorithmist.com/index.php/Euler's_Phi_function
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

long long phi(long long x) {
    long long ret = 1;
    long long i;
    long long pow;
    for (i = 2; x != 1; i++) {
        pow = 1;
        if(i > (int)sqrt((double)x)) {
            break;
        }
        while (!(x % i))  {
            x /= i;
            pow *= i;
        }
        ret *= (pow - (pow / i));
    }
    if(x != 1) {
        ret *= (x - 1);
    }
    return ret;
}

int main() {
    double maxVal = 3.0;
    int res = 0;
    for(int i = 2; i <= 1000000; i++) {
        double t = (double)i / (double)phi(i);
        if(t > maxVal) {
            maxVal = t;
            res = i;
            cout<<i<<" "<<phi(i)<<" "<<t<<endl;
        }
    }
    cout<<"Result "<<res<<endl;

    int wait;
    cin>>wait;

    return 0; 
}
