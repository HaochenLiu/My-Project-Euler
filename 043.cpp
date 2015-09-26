#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNextPandigital(vector<int> num) {
    int n = num.size();
    int i;
    for(i = n - 1; i >= 1; i--) {
        if(num[i] > num[i - 1]) {
            break;
        }
    }
    if(i == 0) {
        num.clear();
        return num;
    }
    for(int j = n - 1; j >= i; j--) {
        if(num[j] > num[i - 1]) {
            swap(num[i - 1], num[j]);
            break;
        }
    }
    reverse(num.begin() + i, num.end());

    return num;
}

void printNum(vector<int> num) {
    int n = num.size();
    for(int i = 0; i < n; i++) {
        cout<<num[i];
    }
    cout<<endl;
}

bool isValid(vector<int> num) {
    if(num[3] % 2 != 0) return false;
    if((num[2] + num[3] + num[4]) % 3 != 0) return false;
    if(num[5] % 5 != 0) return false;
    if((100 * num[4] + 10 * num[5] + num[6]) % 7 != 0) return false;
    if((num[5] + num[7] - num[6]) % 11 != 0) return false;
    if((100 * num[6] + 10 * num[7] + num[8]) % 13 != 0) return false;
    if((100 * num[7] + 10 * num[8] + num[9]) % 17 != 0) return false;

    return true;
}

long long vtoi(vector<int> num) {
    long long l = 0;
    int n = num.size();
    for(int i = 0; i < n; i++) {
        l *= 10;
        l += num[i];
    }
    return l;
}

int main() {
    int n = 10;
    vector<int> num(n, 0);
    num[0] = 1;
    num[1] = 0;
    for(int i = 2; i < n; i++) {
        num[i] = i;
    }

    int last = 1;
    long long res = 0;
    while(!num.empty()) {
        if(isValid(num)) {
            printNum(num);
            res += vtoi(num);
            cout<<"Result "<<res<<endl;
        }
        num = getNextPandigital(num);
        if(!num.empty() && num[0] != last) {
            cout<<"First digit "<<num[0]<<endl;
            last = num[0];
        }
    }

    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
