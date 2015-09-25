#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 1000000;
    int n = 10;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    vector<int> res;
    vector<int> fac(n, 0);
    fac[0] = 1;
    for(int i = 1; i < n; i++) {
        fac[i] = fac[i - 1] * i;
    }

    N--;
    for(int i = 0; i < n; i++) {
        int t = N / fac[n - 1 - i];
        N %= fac[n - 1 - i];
        res.push_back(nums[t]);
        nums.erase(nums.begin() + t);
    }

    for(int i = 0; i < n; i++) {
        cout<<res[i];
    }
    cout<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
