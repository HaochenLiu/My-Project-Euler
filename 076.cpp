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
    int N = 100;
    int* ways = new int[N + 1];
    memset(ways, 0, sizeof(int) * (N + 1));
    ways[0] = 1;
 
    for (int i = 1; i < N; i++) {
        for (int j = i; j <= N; j++) {
            ways[j] += ways[j - i];
        }
    }
    cout<<"Result "<<ways[N]<<endl;

    int wait;
    cin>>wait;

    return 0; 
}
