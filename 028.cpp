#include <iostream>
#include <vector>

using namespace std;

int square(int n) {
    return (n * n);
}

int main() {
    int n = 501;
    vector<long long> res(n, 0);
    res[0] = 1;
    for(int i = 1; i < n; i++) {
        res[i] = res[i - 1];
        res[i] += square(2 * i + 1);
        res[i] += (3 * (1 + square(2 * i))); 
    }

    cout<<res[n - 1]<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
