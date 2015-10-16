#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N = 10;

int getCnt(int* a) {
    if(N == 1) return 0;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        A[i] = a[i];
    }
    int res = 0;
    int i = 0;
    while(true) {
        if(i == N - 1) {
            break;
        }
        if(A[i] > A[i + 1]) {
            res++;
            int t = A[i + 1];
            for(int j = i; j >= 0; j--) {
                A[j + 1] = A[j];
            }
            A[0] = t;
            i = 0;
        } else {
            i++;
        }
    }

    return res;
}

int main() {
    int* A = new int[N];
    for(int i = 0; i < N; i++) {
        A[i] = i + 1;
    }

    int res = 0;
    int cnt = 0;

    do{
        res += getCnt(A);
        cnt++;
    }while(next_permutation(A, A + N));

    cout<<"N "<<N<<endl;
    cout<<"res "<<res<<endl;
    cout<<"cnt "<<cnt<<endl;
    printf("expected %.3f", (double)res / (double)cnt);

    int wait;
    cin>>wait;

    return 0;
}
