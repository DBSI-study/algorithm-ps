#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[4] = { 0, 0, 1, 1 };
int dx[4] = { 0, 1, 0, 1 };

void printBoard(int m, int n, vector<string> board){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int deleteBlock(int m, int n, vector<string>& board){
    vector<vector<pair<int,int>>> pos;
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            vector<pair<int, int>> tempPos;
           	char cmp = board[i][j]; 
            if(cmp == ' ') continue;
            for(int k = 0; k < 4; k++){
                if(cmp == board[i + dy[k]][j + dx[k]]){
                    tempPos.push_back({i + dy[k], j + dx[k]});
                }
            }
            if(tempPos.size() == 4) pos.push_back(tempPos);
        }
    }
    if(pos.size() == 0) return 0;
    
    for(auto vec : pos){
       	for(auto elem : vec){
            board[elem.first][elem.second] = ' ';
        } 
    }
    return 1;
}

void moveBlock(int m, int n, vector<string>& board){
    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            int k = j;
            while(k + 1 < m && board[k + 1][i] == ' '){
                k++;
            }
            if(k != j){
                board[k][i] = board[j][i];
              	board[j][i] = ' '; 
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(1){
        if(deleteBlock(m, n, board) == 0) break;
       	moveBlock(m, n, board); 
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == ' ') answer++;
        }
    }
    return answer;
}