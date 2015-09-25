#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    int N = 1000001;
    int* num = new int[N];
    memset(num, 0, sizeof(num));
    int res = 1;
    int maxCnt = 1;
    for(int i = 1; i < N; i++) {
        if(i % 10000 == 0) {
            cout<<"Milestone "<<i<<endl;
        }
        long long n = i;
        int cnt = 1;
        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            cnt++;
        }
        num[i] = cnt;
        if(cnt > maxCnt) {
            maxCnt = cnt;
            res = i;
            cout<<"i = "<<i<<endl;
            cout<<"maxCnt = "<<maxCnt<<endl;
        }
    }
    
    int wait = 0;
    cin>>wait;

    return 0; 
}
