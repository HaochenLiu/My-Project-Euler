/*
Result 425185

Dijkstra's algorithm
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
https://en.wikipedia.org/wiki/Shortest_path_problem
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
#include <queue>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> res;
    stringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        res.push_back(tok);
    }
  
    return res;
}

struct Node {
    int x;
    int y; 
    int val;
    vector<Node*> neighbour;
    Node(int v) : val(v) {};
};

int getShortestPath(vector<vector<Node>>& a, Node* source, Node* target) {
    if(source == target) return 0;
    if(a.empty() || a[0].empty()) return 0;
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), INT_MAX)); 
    dist[source->x][source->y] = 0;
    queue<Node*> q;
    q.push(source); 
    int res = 0;
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        for(int i = 0; i < cur->neighbour.size(); i++) {
            if(dist[cur->neighbour[i]->x][cur->neighbour[i]->y] > dist[cur->x][cur->y] + a[cur->neighbour[i]->x][cur->neighbour[i]->y].val) {
                dist[cur->neighbour[i]->x][cur->neighbour[i]->y] = dist[cur->x][cur->y] + a[cur->neighbour[i]->x][cur->neighbour[i]->y].val;
                q.push(&(a[cur->neighbour[i]->x][cur->neighbour[i]->y]));
            }
        }
    }
    return dist[target->x][target->y];
}

int main() {
    int N = 80;
    vector<vector<Node>> a(N, vector<Node>(N, 0));
    for(int i = 0; i < N; i++) {
        string s;
        cin>>s;
        vector<string> str = split(s, ',');
        for(int j = 0; j < N; j++) {
            a[i][j].x = i;
            a[i][j].y = j;
            a[i][j].val = stoi(str[j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            a[i][j].neighbour.push_back((&a[i][j + 1]));
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            a[i][j].neighbour.push_back((&a[i][j - 1]));
        }
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j].neighbour.push_back((&a[i + 1][j]));
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j].neighbour.push_back((&a[i - 1][j]));
        }
    }

    Node* source = &(a[0][0]);
    Node* target = &(a[N - 1][N - 1]);

    int res = getShortestPath(a, source, target);
    res += a[source->x][source->y].val;

    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
