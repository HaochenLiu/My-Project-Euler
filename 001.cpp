#include <iostream>

using namespace std;

int main() {
    int res = 0;
    for(int i = 1; i < 1000; i++) {
        if((i % 3 == 0) || (i % 5 == 0)) {
            res += i;
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
