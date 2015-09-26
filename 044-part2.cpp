/*
我们得到了一个D = 5482660，但并不能确定这是最小的。需要检验。
如果要求Pk-Pj<D。假设j最接近k，也就是j=k-1。得到Pk-Pj=3k-2。如果3k-2>=D，那么就不可能有满足条件的k和j了。
也就得到k<1827554。只要检验过这些k，没有比当前D值更小的。就完成任务了。
可能遇到的Pk+Pj，上界为P(2k)。
*/

#include <iostream>

using namespace std;

long long N = 1827554;
long long D = 5482660;

long long getPentagonal(long long n) {
    return (n * (3 * n - 1) / 2);
}

bool isPentagonal(long long n) {
    long long low = 1;
    long long high = 2 * N;
    while(low <= high) {
        long long mid = (low + high) / 2;
        int t = getPentagonal(mid);
        if(t == n) {
            return true;
        } else if(t < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    for(long long k = 1; k < N; k++) {
        for(long long j = k - 1; j >= 1; j--) {
            if(getPentagonal(k) - getPentagonal(j) > D) {
                break;
            }
            if(isPentagonal(getPentagonal(k) - getPentagonal(j))
            && isPentagonal(getPentagonal(k) + getPentagonal(j))) {
                D = getPentagonal(k) - getPentagonal(j);
                cout<<"k "<<k<<" j "<<j<<" D "<<D<<endl;
            }
        }
    }
    cout<<"Result "<<D<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
