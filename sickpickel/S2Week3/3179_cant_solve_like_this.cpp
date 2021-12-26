#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int, int>

using namespace std;

int R, C;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char Lake[Max][Max];

int canMeet(pii start, pii end){
	bool visited[Max][Max];
	queue<pii> q;
	q.push(start);
	visited[start.first][start.second] = 1;
	
	while(!q.empty()){
		pii now = q.front();
		
		q.pop();
		
		if(now == end) return 1;
		
		for(int i = 0; i < 4; i++){
			int nextY = now.first + dy[i];
			int nextX = now.second + dx[i];
			if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
			if(visited[nextY][nextX] || Lake[nextY][nextX] == 'X') continue;
			visited[nextY][nextX] = 1;
			q.push({nextY, nextX});
		}
	}
	return 0;
}
int isNearWater(pii pos){
	for(int i = 0; i < 4; i++){
		int ni = pos.first + dy[i];	
		int nj = pos.second + dx[i];	
		if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		if(Lake[ni][nj] == '.') return 1;
	}	
	return 0;
}

void meltIce(){
	char tempLake[Max][Max];	
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(Lake[i][j] != 'L' && isNearWater({i, j})) tempLake[i][j] = '.';
			else tempLake[i][j] = Lake[i][j];
		}
	}
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			Lake[i][j] = tempLake[i][j];
		}
	}
}

int main(void){
	vector<pii> swanLocation;
	cin >> R >> C;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> Lake[i][j];
			if(Lake[i][j] == 'L')
				swanLocation.push_back({i, j});
		}
	}

	int answer = 0;
	while(!canMeet(swanLocation[0], swanLocation[1])){
		meltIce();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}