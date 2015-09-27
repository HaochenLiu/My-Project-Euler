/*
验证了一下数据规模，发现每个vector大约有几十个数字。并且有很多重复。
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    vector<int> Triangle;
    vector<int> Square;
    vector<int> Pentagonal;
    vector<int> Hexagonal;
    vector<int> Heptagonal;
    vector<int> Octagonal;

    set<int> s;
    int N = 10000;
    for(int i = 1; i < N; i++) {
        int t = i * (i + 1) / 2;
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Triangle.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Triangle size "<<Triangle.size()<<endl;

    for(int i = 1; i < N; i++) {
        int t = i * i;
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Square.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Square size "<<Square.size()<<endl;

    for(int i = 1; i < N; i++) {
        int t = i * (3 * i - 1) / 2;
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Pentagonal.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Pentagonal size "<<Pentagonal.size()<<endl;

    for(int i = 1; i < N; i++) {
        int t = i * (2 * i - 1);
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Hexagonal.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Hexagonal size "<<Hexagonal.size()<<endl;

    for(int i = 1; i < N; i++) {
        int t = i * (5 * i - 3) / 2;
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Heptagonal.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Heptagonal size "<<Heptagonal.size()<<endl;

    for(int i = 1; i < N; i++) {
        int t = i * (3 * i - 2);
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Octagonal.push_back(t);
            s.insert(t);
        }
    }
    cout<<"Octagonal size "<<Octagonal.size()<<endl;

    cout<<"Set size "<<s.size()<<endl;

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
