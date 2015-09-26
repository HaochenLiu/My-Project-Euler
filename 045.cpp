#include <iostream>
#include <math.h>

using namespace std;

long long getTriangle(long long n) {
    return (n * (n + 1) / 2);
}

bool isTriangle(long long n) {
    long long low = 1;
    long long high = (int)sqrt((double)(2 * n));
    while(low <= high) {
        long long mid = (low + high) / 2;
        int t = getTriangle(mid);
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

long long getPentagonal(long long n) {
    return (n * (3 * n - 1) / 2);
}

bool isPentagonal(long long n) {
    long long low = 1;
    long long high = (int)sqrt((double)n);
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

long long getHexagonal(long long n) {
    return (n * (2 * n - 1));
}

bool isHexagonal(long long n) {
    long long low = 1;
    long long high = (int)sqrt((double)n);
    while(low <= high) {
        long long mid = (low + high) / 2;
        int t = getHexagonal(mid);
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
    int N = 100000;
    for(long long i = 1; i < N; i++) {
        if(isPentagonal(getHexagonal(i))
        && isTriangle(getHexagonal(i))) {
            cout<<"i "<<i<<" num "<<getHexagonal(i)<<endl;
        }
    }
    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
