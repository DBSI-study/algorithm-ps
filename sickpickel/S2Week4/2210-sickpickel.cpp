#include <bits/stdc++.h>

using namespace std;

int board[5][5];
int saveNumber[1000000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int cnt, int number){
    if(cnt == 5){
        saveNumber[number] = 1;
        return;
    }

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
        dfs(ny, nx, cnt + 1, number * 10 + board[ny][nx]);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j]; 
        }
    }

    for(int i = 0; i < 5; i++) 
        for(int j = 0; j < 5; j++) 
            dfs(i, j, 0, board[i][j]);

    int answer = 0;
    for(int i = 0; i < 1000000; i++) 
        { if(saveNumber[i]) answer++; }

    cout << answer << "\n";
    return 0;
}