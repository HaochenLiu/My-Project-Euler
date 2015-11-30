/*
结果不准
*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    const int N = 100;
    int n = 10;
    string str[N];
    long long num[N];
    long long res = 0;
    for(int i = 0; i < N; i++) {
        cin>>str[i];
        str[i] = str[i].substr(0, n);
        num[i] = stoll(str[i]);
        res += num[i];
    }

    while(res > pow((double)10, (double)10)) {
        res /= 10;
    }

    cout<<res<<endl;
    
    int wait = 0;
    cin>>wait;

    return 0; 
}
