/*
http://www.mathblog.dk/project-euler-79-secret-numeric-passcode/
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    const int N =  50;
    string pw[N];
    for(int i = 0; i < N; i++) {
        cin>>pw[i];
    }

    vector<vector<bool>> edge(10, vector<bool>(10, false));
    for (int i = 0; i < N; i++) {
        edge[pw[i][1] - '0'][pw[i][0] - '0'] = true;
        edge[pw[i][2] - '0'][pw[i][0] - '0'] = true;
        edge[pw[i][2] - '0'][pw[i][1] - '0'] = true;
    }
 
    for (int i = 0; i < 10; i++) {
        cout<<"Comes before "<< i<<": ";
        for (int j = 0; j < 10; j++) {
            if (edge[i][j]) {
                cout<<j<<", ";
            }
        }
        cout<<endl;
    }
 
    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
