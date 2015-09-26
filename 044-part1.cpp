/*
Output:
k = 2167
j = 1020
D = 5482660
*/

#include <iostream>
#include <vector>

using namespace std;

int getPentagonal(int n) {
    return (n * (3 * n - 1) / 2);
}

int main() {
    int N = 10000;
    vector<bool> pen(getPentagonal(N) + 1, false);
    for(int i = 1; i <= N; i++) {
        pen[getPentagonal(i)] = true;
    }

    int minVal = INT_MAX;
    for(int k = 1; k <= N; k++) {
        for(int j = 1; j < k; j++) {
            if(pen[getPentagonal(k) - getPentagonal(j)]
            && (getPentagonal(k) + getPentagonal(j) <= getPentagonal(N))
            && pen[getPentagonal(k) + getPentagonal(j)]) {
                if(getPentagonal(k) - getPentagonal(j) < minVal) {
                    minVal = getPentagonal(k) - getPentagonal(j);
                    cout<<"k "<<k<<" j "<<j<<" minVal "<<minVal<<endl;
                }
            }
        }
    }
    cout<<"Result "<<minVal<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
