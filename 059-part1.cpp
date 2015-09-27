/*
三个小写字母的秘钥。之后搜索the。
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <set>
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

int main() {
    string s;
    cin>>s;
    vector<string> str = split(s, ',');
    int N = str.size();
    cout<<N<<" letters"<<endl;
    string text;
    for(int i = 0; i < N; i++) {
        int t = stoi(str[i]);
        text.append(1, (char)t);
    }

    int maxCnt = 0;
    for(int key = 0; key < 26 * 26 * 26; key++) {
        char k[3];
        k[0] = 'a' + key / 26 / 26;
        k[1] = 'a' + key / 26 % 26;
        k[2] = 'a' + key % 26;

        string tmpKey;
        tmpKey.resize(N);
        for(int i = 0; i < N; i++) {
            tmpKey[i] = k[i % 3];
        }

        for(int i = 0; i < N; i++) {
            tmpKey[i] ^= text[i];
        }

        int cnt = 0;
        for(int i = 0; i < N - 2; i++) {
            if(tmpKey[i] == 't' && tmpKey[i + 1] == 'h' && tmpKey[i + 2] == 'e') {
                cnt++;
            }
        }

        if(cnt > maxCnt) {
            maxCnt = cnt;
            cout<<"maxCnt "<<maxCnt<<endl;
            cout<<"k[0] "<<k[0]<<endl;
            cout<<"k[1] "<<k[1]<<endl;
            cout<<"k[2] "<<k[2]<<endl;
        }
    }
    
    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
