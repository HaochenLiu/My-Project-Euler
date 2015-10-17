#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N = 30;
    double res = 0.0;
    for(int i = 2; i <= N; i++) {
        res += (double)(pow((double)2, i - 1) - 1) / (double)i;
    }

    printf("%.4f", res);

    int wait;
    cin>>wait;

    return 0;
}
