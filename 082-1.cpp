/*
Result 260324

DP
Time: O(n^2)
Space: O(n^2) can be reduce to O(n)
http://www.mathblog.dk/project-euler-82-find-the-minimal-path-sum-from-the-left-column-to-the-right-column/
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
    for(int i = 0; i < N; i++) {
        dp[i][N - 1] = a[i][N - 1];
    }

    for(int j = N - 2; j >= 0; j--) {
        dp[0][j] = dp[0][j + 1] + a[0][j];
        for(int i = 1; i < N; i++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + a[i][j];
        }
        for(int i = N - 2; i >= 0; i--) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[i][j]);
        }
    }

    int res = INT_MAX;
    for(int i = 0; i < N; i++) {
        res = min(res, dp[i][0]);
    }

    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
