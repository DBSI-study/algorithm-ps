#include <bits/stdc++.h>
#define Max 30

using namespace std;

int N;
int dy[4] = { 0, 0, 1, -1};
int dx[4] = { 1, -1, 0, 0};
int visited[Max][Max];
long double prov[4], answer = 0;

void dfs(int nowY, int nowX, long double currnetProv, int cnt){
	if(cnt == N){
		answer += currnetProv;
		return;
	}
	
    for(int i = 0; i < 4; i++){
        int nextY = nowY + dy[i];
        int nextX = nowX + dx[i];
		
        if(nextY < 0 || nextY > 28 || nextX < 0 || nextX > 28) continue;
        if(visited[nextY][nextX] == 1) continue;

		visited[nextY][nextX] = 1;
        dfs(nextY, nextX, currnetProv * prov[i] / 100l, cnt + 1);
		visited[nextY][nextX] = 0;
    } 
}

int main(void){
    int before = 0, direction = 0;
    cin >> N;
    for(int i = 0; i < 4; i++){
        cin >> prov[i];
    }
	
    int startY = 14, startX = 14;
	visited[startY][startX] = 1;
    dfs(startY, startX, 1, 0);
	
	cout << setprecision(15) << answer << "\n";
    return 0;
}