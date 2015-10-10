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

int N = 9;

bool isValid(vector<vector<char>>& board, int x, int y) {
    //check line
    for(int j = 0; j < N; j++) {
        if(j != y && board[x][j] == board[x][y]) {
            return false;
        }
    }
        
    //check colume
    for(int i = 0; i < N; i++) {
        if(i != x && board[i][y] == board[x][y]) {
            return false;
        }
    }
        
    //check block
    for(int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
        for(int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {
            if((i != x || j != y) && board[i][j] == board[x][y]) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuRecur(vector<vector<char>>& board) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != '0') {
                continue;
            }
            for(int k = 1; k <= 9; k++) {
                board[i][j] = k + '0';
                if(isValid(board, i, j)) {
                    if(solveSudokuRecur(board)) {
                        return true;
                    }
                }
            }
            board[i][j] = '0';
            return false;
        }
    }
}

int main() {
    int N2 = 50;
    int res = 0;
    vector<vector<char>> board(N, vector<char>(N, 0));

    for(int i = 0; i < N2; i++) {
        string t;
        cin>>t;
        cin>>t;
        for(int j = 0; j < N; j++) {
            cin>>t;
            for(int k = 0; k < N; k++) {
                board[j][k] = t[k];
            }
        }
        solveSudokuRecur(board);
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cout<<board[j][k];
            }
            cout<<endl;
        }
        cout<<endl;
        res += 100 * (board[0][0] - '0');
        res += 10 * (board[0][1] - '0');
        res += (board[0][2] - '0');
    }

    cout<<"Result = "<<res<<endl;

    int wait;
    cin>>wait;

    return 0; 
}
