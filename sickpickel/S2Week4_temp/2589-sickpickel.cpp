#include <bits/stdc++.h>
#define Max 51
#define pii pair<int, int>

using namespace std;

int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char treasureMap[Max][Max];

int bfs(int sy, int sx){
	int ret = 0;
	int visited[Max][Max] = {};
	queue<pair<pii, int>> q;
	
	q.push({{sy, sx}, 0});
	visited[sy][sx] = 1;
	
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int distance = q.front().second;
		q.pop();
		
		ret = max(ret, distance);
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if(visited[ny][nx] || treasureMap[ny][nx] == 'W') continue;
			visited[ny][nx] = 1;
			q.push({{ny, nx}, distance + 1});
		}
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> treasureMap[i][j];
		}
	}
	int save_max = 0;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(treasureMap[i][j] == 'W') continue;
			save_max = max(save_max, bfs(i, j));
		}
	}	
	cout << save_max << "\n";
	return 0;
}