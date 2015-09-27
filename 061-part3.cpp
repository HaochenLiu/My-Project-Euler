/*
再解决6个的问题。
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

int cycle = 6;

void dfs(vector<vector<bool>>& graph, vector<vector<int>>& res, vector<int>& candidate, vector<int>& path, vector<bool>& visited, int node, int sz) {
    path.push_back(node);
    visited[node] = true;
    if(path.size() == cycle + 1) {
        if(node == path[0]) {
            res.push_back(path);
            for(int i = 0; i < path.size(); i++) {
                cout<<candidate[path[i]]<<" ";
            }
            cout<<endl;
        }
        path.pop_back();
        visited[node] = false;
        return;
    }
    for(int i = 0; i < sz; i++) {
        if(graph[node][i]) {
            dfs(graph, res, candidate, path, visited, i, sz);
        }
    }
    path.pop_back();
    visited[node] = false;
}

bool isValid(vector<int>& num, vector<int>& candidate, map<int, int>& Triangle, map<int, int>& Square, map<int, int>& Pentagonal, map<int, int>& Hexagonal, map<int, int>& Heptagonal, map<int, int>& Octagonal) {
    num.pop_back();
    vector<int> vote;
    vector<vector<int>> representive(cycle, vote);

    vote.clear();
    for(int i = 0; i < cycle; i++) {
        if(Triangle.find(candidate[num[i]]) != Triangle.end()) {
            representive[i].push_back(0);
        }
        if(Square.find(candidate[num[i]]) != Square.end()) {
            representive[i].push_back(1);
        }
        if(Pentagonal.find(candidate[num[i]]) != Pentagonal.end()) {
            representive[i].push_back(2);
        }
        if(Hexagonal.find(candidate[num[i]]) != Hexagonal.end()) {
            representive[i].push_back(3);
        }
        if(Heptagonal.find(candidate[num[i]]) != Heptagonal.end()) {
            representive[i].push_back(4);
        }
        if(Octagonal.find(candidate[num[i]]) != Octagonal.end()) {
            representive[i].push_back(5);
        }
    }

    for(int i0 = 0; i0 < representive[0].size(); i0++) {
        for(int i1 = 0; i1 < representive[1].size(); i1++) {
            if(representive[1][i1] == representive[0][i0]) {
                continue;
            }
            for(int i2 = 0; i2 < representive[2].size(); i2++) {
                if(representive[2][i2] == representive[0][i0]) {
                    continue;
                }
                if(representive[2][i2] == representive[1][i1]) {
                    continue;
                }
                for(int i3 = 0; i3 < representive[3].size(); i3++) {
                    if(representive[3][i3] == representive[0][i0]) {
                        continue;
                    }
                    if(representive[3][i3] == representive[1][i1]) {
                        continue;
                    }
                    if(representive[3][i3] == representive[2][i2]) {
                        continue;
                    }
                    for(int i4 = 0; i4 < representive[4].size(); i4++) {
                        if(representive[4][i4] == representive[0][i0]) {
                            continue;
                        }
                        if(representive[4][i4] == representive[1][i1]) {
                            continue;
                        }
                        if(representive[4][i4] == representive[2][i2]) {
                            continue;
                        }
                        if(representive[4][i4] == representive[3][i3]) {
                            continue;
                        }
                        for(int i5 = 0; i5 < representive[5].size(); i5++) {
                            if(representive[5][i5] == representive[0][i0]) {
                                continue;
                            }
                            if(representive[5][i5] == representive[1][i1]) {
                                continue;
                            }
                            if(representive[5][i5] == representive[2][i2]) {
                                continue;
                            }
                            if(representive[5][i5] == representive[3][i3]) {
                                continue;
                            }
                            if(representive[5][i5] == representive[4][i4]) {
                                continue;
                            }
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    map<int, int> Triangle;
    map<int, int> Square;
    map<int, int> Pentagonal;
    map<int, int> Hexagonal;
    map<int, int> Heptagonal;
    map<int, int> Octagonal;

    set<int> s;
    int N = 10000;
    for(int i = 1; i < N; i++) {
        int t = i * (i + 1) / 2;
        if(t >= 10000) {
            break;
        }
        if(t >= 1000) {
            Triangle[t]++;
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
            Square[t]++;
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
            Pentagonal[t]++;
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
            Hexagonal[t]++;
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
            Heptagonal[t]++;
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
            Octagonal[t]++;
            s.insert(t);
        }
    }
    cout<<"Octagonal size "<<Octagonal.size()<<endl;

    cout<<"Set size "<<s.size()<<endl;
    int sz = s.size();
    vector<int> candidate(sz, 0);
    int idx = 0;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        candidate[idx] = (*it);
        idx++;
    }

    for(int i = 0; i < sz; i++) {
        cout<<candidate[i]<<" ";
    }
    cout<<endl;

    vector<vector<bool>> graph(sz, vector<bool>(sz, false));
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            if(candidate[i] % 100 == candidate[j] / 100) {
                graph[i][j] = true;
            }
        }
    }

    vector<int> path;
    vector<bool> visited(sz, false);
    vector<vector<int>> res;
    for(int i = 0; i < sz; i++) {
        dfs(graph, res, candidate, path, visited, i, sz);
    }
    
    for(int i = 0; i < res.size(); i++) {
        if(isValid(res[i], candidate, Triangle, Square, Pentagonal, Hexagonal, Octagonal, Heptagonal)) {
            int sum = 0;
            for(int j = 0; j < res[i].size(); j++) {
                cout<<candidate[res[i][j]]<<endl;
                sum += candidate[res[i][j]];
            }
            cout<<"sum "<<sum<<endl;
        }
    }

    cout<<"Result "<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
