#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isDivisable(int n) {
    while(n % 2 == 0) {
        n /= 2;
    }
    while(n % 5 == 0) {
        n /= 5;
    }

    return (n == 1);
}

int getRecur(int n) {
    if(isDivisable(n)) return 0;
    unordered_map<int, int> m;
    int left = 1;
    while(true) {
        if(m.find(left) != m.end()) {
            return (m.size() - m[left] + 1);
        }
        int sz = m.size();
        m[left] = sz + 1;
        left *= 10;
        left %= n;
    }

    return 0;
}

int main() {
    int limit = 1000;
    int maxVal = 0;
    int idx = 3;
    for(int i = 3; i < limit; i++) {
        if(maxVal < getRecur(i)) {
            maxVal = getRecur(i);
            idx = i;
        }
    }
    cout<<idx<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
