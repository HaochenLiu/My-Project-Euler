#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ndays[] = {31, 28, 31,30, 31, 30,31,31, 30, 31, 30, 31};
    int k = 0;
    int total = 0;
    for(int i = 0; i < 12; i++) {
        k += ndays[i];
    }

    for(int year = 1901; year < 2001; year++) {
        if(!(year % 4) || (!(year % 100) && !(year % 400))) {
            ndays[1] = 29;
        } else { 
            ndays[1] = 28;
        }

        for(int i = 0; i < 12; i++) {
            if(!((k - 1) % 7)) {
                total++;
            }
            k += ndays[i];
        }
    }
    cout<<total<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
