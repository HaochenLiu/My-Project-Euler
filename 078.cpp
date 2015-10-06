/*
http://www.mathblog.dk/project-euler-78-coin-piles/
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

int main() {
    vector<int> v;
    v.push_back(1);
             
    int n = 1;            
    while(true){
        int i = 0;
        int penta = 1;
        v.push_back(0);
        while(penta <= n){                    
            int sign = (i % 4 > 1) ? -1 : 1;
            v[n] += sign * v[n - penta];
            v[n] %= 1000000;
            i++;
            int j = (i % 2 == 0) ? i / 2 + 1 : -(i / 2 + 1);
            penta = j * (3 * j - 1) / 2;
        } 
                 
        if (v[n] == 0) {
            break;
        }
        n++;
    }

    cout<<"Result "<<n<<endl;
    
    int wait;
    cin>>wait;

    return 0; 
}
