/*
Result 260324
Result 425547

Floyd–Warshall algorithm
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
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

int** getShortestPath(vector<vector<Node>>& a) {
    int** dist = NULL;
    if(a.empty() || a[0].empty()) return dist;
    int N1 = a.size();
    int N2 = a[0].size();
    int V = N1 * N2;
    dist = new int*[V];
    for(int i = 0; i < V; i++) {
        dist[i] = new int[V];
        for(int j = 0; j < V; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    /* Step 1: remove loops */
    /* Step 2: remove all parallel edges between two vertex except the one with least weight */

    /* Step 3: set distance */
    for(int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < V; i++) {
        int ix = i / N2;
        int iy = i % N2;
        for(int j = 0; j < a[ix][iy].neighbour.size(); j++) {
            int nx = a[ix][iy].neighbour[j]->x;
            int ny = a[ix][iy].neighbour[j]->y;
            dist[ix * N2 + iy][nx * N2 + ny] = a[nx][ny].val;
        }
    }

    /* Step 4: 3 loops */
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
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

    int** dist = getShortestPath(a);
    int V = N * N;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i != j) {
                dist[i][j] += a[i / N][i % N].val;
            }
        }
    }

    int res = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res = min(res, dist[i * N][j * N + N - 1]);
        }
    }
    cout<<"Result "<<res<<endl;
    cout<<"Result "<<dist[0][V - 1]<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
