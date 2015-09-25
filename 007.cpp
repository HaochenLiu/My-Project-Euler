#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N = 200001;
    bool* flag = new bool[N];
    memset(flag, true, sizeof(flag));
    flag[0] = false;
    flag[1] = false;
    for(int i = 2; i <= sqrt((double)N); i++) {
        for(int j = 2 * i; j < N; j += i) {
            flag[j] = false;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(flag[i]) {
            cnt++;
            if(cnt == 10001) {
                cout<<"res = "<<i<<endl;
                break;
            }
        }
    }

    delete[] flag;

    int wait = 0;
    cin>>wait;

    return 0; 
}
