#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    string s[1001];
    memset(s, 0, sizeof(s));
    s[0] = "";
    s[1] = "one";
    s[2] = "two";
    s[3] = "three";
    s[4] = "four";
    s[5] = "five";
    s[6] = "six";
    s[7] = "seven";
    s[8] = "eight";
    s[9] = "nine";
    s[10] = "ten";
    s[11] = "eleven";
    s[12] = "twelve";
    s[13] = "thirteen";
    s[14] = "fourteen";
    s[15] = "fifteen";
    s[16] = "sixteen";
    s[17] = "seventeen";
    s[18] = "eighteen";
    s[19] = "nineteen";
    s[20] = "twenty";
    s[30] = "thirty";
    s[40] = "forty";
    s[50] = "fifty";
    s[60] = "sixty";
    s[70] = "seventy";
    s[80] = "eighty";
    s[90] = "ninety";

    for(int i = 1; i < 1000; i++) {
        if(s[i] == "") {
            if(i < 100) {
                s[i] = s[i / 10 * 10] + s[i % 10];
            } else {
                s[i] = s[i / 100] + "hundred";
                if(i % 100) {
                    s[i] += "and" + s[i % 100];
                }
            }
        }
    }
    s[1000] = "onethousand";

    int total = 0;
    for(int i = 1; i <= 1000; i++) {
        total += s[i].size();
    }
    cout<<total<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
