#include <iostream>

using namespace std;

string itos(int n) {
    string res = "";
    if(n == 0) return "0";
    if(n < 0) {
        res = "-";
        res += itos(-n);
        return res;
    }
    while(n > 0) {
        res.append(1, '0' + n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string str;

int main() {
    str = "";
    int N = 1000000;
    for(int i = 1; i < N; i++) {
        str += itos(i);
        if(str.size() > N) {
            break;
        }
    }

    int res = 1;
    res *= (str[0] - '0');
    cout<<res<<endl;

    res *= (str[9] - '0');
    cout<<res<<endl;

    res *= (str[99] - '0');
    cout<<res<<endl;

    res *= (str[999] - '0');
    cout<<res<<endl;

    res *= (str[9999] - '0');
    cout<<res<<endl;

    res *= (str[99999] - '0');
    cout<<res<<endl;

    res *= (str[999999] - '0');
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
