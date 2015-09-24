#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int sum_square = 0;
    for(int i = 1; i <= 100; i++) {
        sum += i;
        sum_square += (i * i);
    }
    
    cout<<"res = "<<sum * sum - sum_square<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
