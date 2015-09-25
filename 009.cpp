#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isSquare(int n) {
    int t = (int)sqrt((double)n);
    return (t * t == n);
}

int main() {
    for(int a = 1; a < 1000; a++) {
        for(int b = a + 1; b < 1000; b++) {
            if(isSquare(a * a + b * b)) {
                if(a + b + (int)sqrt((double)a * a + b * b) == 1000) {
                    long long res = a * b * (int)sqrt((double)a * a + b * b);
                    cout<<res<<endl;
                }
            }
        }
    }

    int wait = 0;
    cin>>wait;

    return 0; 
}
