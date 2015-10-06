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

int p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

bool CheckResult() {
    if (p[1] == 10 ||
        p[2] == 10 ||
        p[4] == 10 ||
        p[6] == 10 ||
        p[8] == 10) return false;
 
    if (p[0] > p[3] ||
        p[0] > p[5] ||
        p[0] > p[7] ||
        p[0] > p[9] ) return false;
 
    if (p[0] + p[1] + p[2] != p[3] + p[2] + p[4]) return false;
    if (p[0] + p[1] + p[2] != p[5] + p[4] + p[6]) return false;
    if (p[0] + p[1] + p[2] != p[7] + p[6] + p[8]) return false;
    if (p[0] + p[1] + p[2] != p[9] + p[8] + p[1]) return false;
 
    return true;
}

int main() {
    string result = "0000000000000000";
    while (true) {
        if (!next_permutation(p, p + 10)) {
            break;
        }
        if (CheckResult()) {
            string candidate = "";
            candidate.append(1, '0' + p[0]);
            candidate.append(1, '0' + p[1]);
            candidate.append(1, '0' + p[2]);
            candidate.append(1, '0' + p[3]);
            candidate.append(1, '0' + p[2]);
            candidate.append(1, '0' + p[4]);
            candidate.append(1, '0' + p[5]);
            candidate.append(1, '0' + p[4]);
            candidate.append(1, '0' + p[6]);
            candidate.append(1, '0' + p[7]);
            candidate.append(1, '0' + p[6]);
            candidate.append(1, '0' + p[8]);
            candidate.append(1, '0' + p[9]);
            candidate.append(1, '0' + p[8]);
            candidate.append(1, '0' + p[1]);
            for(int i = 0; i < candidate.size(); i++) {
                if(candidate[i] == ':') {
                    candidate.erase(candidate.begin() + i);
                    candidate.insert(i, "10");
                }
            }
            if (candidate > result) {
                result = candidate;
            }
        }
    }

    cout<<"Result "<<result<<endl;
    
    int wait;
    cin>>wait;

    return 0; 
}
