#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
  
    return internal;
}

int getScores(string s) {
    int n = s.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '"') {
            res += (s[i] - 'A' + 1);
        }
    }
    return res;
}

int main() {
    string s;
    cin>>s;
    vector<string> str = split(s, ',');
    int N = str.size();
    cout<<N<<" names"<<endl;
    sort(str.begin(), str.end());

    long long res = 0;
    for(int i = 0; i < N; i++) {
        res += ((i + 1) * getScores(str[i]));
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
