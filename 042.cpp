#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map> 

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
    cout<<N<<" words"<<endl;

    int maxScore = 0;
    for(int i = 0; i < N; i++) {
        maxScore = max(maxScore, getScores(str[i]));
    }
    cout<<"maxScore "<<maxScore<<endl;

    unordered_map<int, bool> m;
    for(int i = 0; i <= 20; i++) {
        m[i * (i + 1) / 2] = true;
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(m.find(getScores(str[i])) != m.end()) {
            res++;
        }
    }
    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
