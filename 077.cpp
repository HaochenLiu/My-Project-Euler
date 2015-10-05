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

bool* prime;
int N = 100;

int main() {
    prime = new bool[N];
    memset(prime, true, sizeof(bool) * N);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            prime[j] = false;
        }
    }

    vector<int> primev;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            primev.push_back(i);
        }
    }

    int target = 2;           
    while (true) {
        int* ways = new int[target + 1];
        memset(ways, 0, sizeof(int) * (target + 1));
        ways[0] = 1;
 
        for (int i = 0; i < primev.size(); i++) {                    
            for (int j = primev[i]; j <= target; j++) {
                ways[j] += ways[j - primev[i]];
            }
        }
                                 
        if (ways[target] > 5000) {
            break;
        }
        delete[] ways;
        target++;
    }
    cout<<"Result "<<target<<endl;

    int wait;
    cin>>wait;

    return 0; 
}
