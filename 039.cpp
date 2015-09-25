#include <iostream>

using namespace std;

bool isValid(int a, int b, int c) {
    return (a * a + b * b == c * c);
}

int main() {
    int N = 1000;

    int maxCnt = 0;
    int maxIdx = 12;

    for(int p = 12; p <= N; p++) {
        int cnt = 0;
        for(int a = 1; a <= p / 3; a++) {
            for(int b = a + 1; b <= p - 2 * a; b++) {
                if(p - a - b <= b) {
                    break;
                }
                if(isValid(a, b, p - a - b)) {
                    cnt++;
                }
            }
        }
        if(cnt > maxCnt) {
            maxCnt = cnt;
            maxIdx = p;
            maxCnt = max(maxCnt, cnt);
            cout<<p<<" "<<cnt<<endl;
        }
    }
    cout<<maxIdx<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
