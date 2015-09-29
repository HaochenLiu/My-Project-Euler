/*
Result 427337

DP
Time: O(n^2)
Space: O(n^2) can be reduce to O(n)
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
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> res;
    stringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        res.push_back(tok);
    }
  
    return res;
}

int main() {
    int N = 80;
    vector<vector<int>> a(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        string s;
        cin>>s;
        vector<string> str = split(s, ',');
        for(int j = 0; j < N; j++) {
            a[i][j] = stoi(str[j]);
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = a[0][0];
    for(int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    for(int j = 1; j < N; j++) {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout<<"Result "<<dp[N - 1][N - 1]<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
