#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const int N = 20;
    int a[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin>>a[i][j];
        }
    }

    int n = 4;
    int maxVal = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - n + 1; j++) {
            int tmp = 1;
            for(int k = 0; k < n; k++) {
                tmp *= a[i][j + k];
            }
            maxVal = max(maxVal, tmp);
        }
    }

    for(int i = 0; i < N - n + 1; i++) {
        for(int j = 0; j < N; j++) {
            int tmp = 1;
            for(int k = 0; k < n; k++) {
                tmp *= a[i + k][j];
            }
            maxVal = max(maxVal, tmp);
        }
    }

    for(int i = 0; i < N - n + 1; i++) {
        for(int j = 0; j < N - n + 1; j++) {
            int tmp = 1;
            for(int k = 0; k < n; k++) {
                tmp *= a[i + k][j + k];
            }
            maxVal = max(maxVal, tmp);
        }
    }

    for(int i = n - 1; i < N; i++) {
        for(int j = 0; j < N - n + 1; j++) {
            int tmp = 1;
            for(int k = 0; k < n; k++) {
                tmp *= a[i - k][j + k];
            }
            maxVal = max(maxVal, tmp);
        }
    }

    cout<<maxVal<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
