#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 15;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin>>a[i][j];
        }
    }

    for(int j = 0; j < n; j++) {
        dp[n - 1][j] = a[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout<<dp[0][0]<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
