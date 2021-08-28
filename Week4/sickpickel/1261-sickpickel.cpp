#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 101

using namespace std;

int N, M;
char maze[Max][Max];
int visited[Max][Max];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs_djik(pii start, pii end){
	priority_queue<pair<int, pii>> pq;
	pq.push({0, start});
	
	while(!pq.empty())	{
		pii now = pq.top().second;
		int broken_wall_cnt = -pq.top().first;
		pq.pop();
		
		if(visited[now.first][now.second]) continue;
		visited[now.first][now.second] = 1;
		
		if(now == end){
			return broken_wall_cnt;
		}
		for(int i = 0; i < 4; i++){
			int ny = now.first + dy[i];	
			int nx = now.second + dx[i];	
			if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if(visited[ny][nx]) continue;
			int next_broken_wall_cnt = broken_wall_cnt;
			if(maze[ny][nx] == '1') next_broken_wall_cnt++;
			pq.push({-next_broken_wall_cnt, {ny, nx}});
		}
	}
	return -1;
}

int broken_wall_min_count(){
	return bfs_djik({0, 0}, {N - 1, M - 1});
}

int main(void){
	cin >> M >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> maze[i][j];	
		}
	}
	
	cout << broken_wall_min_count() << "\n";	
	return 0;
}