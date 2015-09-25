#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int unit[101];
int unit_1000 = 8;
int unit_and = 3;

int getLetterCnt(int n) {
    if(n <= 20) return unit[n];
    if(n < 100) return (unit[n / 10 * 10] + unit[n % 10]);
    if(n == 1000) return (unit[1] + unit_1000);
    if(n % 100 == 0) return (unit[n / 100] + unit[100]);
    return (unit[n / 100] + unit[100] + unit_and + getLetterCnt(n % 100));
}

int main() {
    memset(unit, 0, sizeof(unit));
    unit[1] = 3;
    unit[2] = 3;
    unit[3] = 5;
    unit[4] = 4;
    unit[5] = 4;
    unit[6] = 3;
    unit[7] = 5;
    unit[8] = 5;
    unit[9] = 4;
    unit[10] = 3;
    unit[11] = 6;
    unit[12] = 6;
    unit[13] = 8;
    unit[14] = 8;
    unit[15] = 7;
    unit[16] = 7;
    unit[17] = 9;
    unit[18] = 8;
    unit[19] = 8;
    unit[20] = 6;
    unit[30] = 6;
    unit[40] = 5;
    unit[50] = 5;
    unit[60] = 5;
    unit[70] = 7;
    unit[80] = 6;
    unit[90] = 6;
    unit[100] = 7;

    int res = 0;
    for(int i = 1; i <= 1000; i++) {
        res += getLetterCnt(i); 
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
