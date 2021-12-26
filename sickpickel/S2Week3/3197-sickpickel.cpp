#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int,int>

using namespace std;

int R, C;
char Lake[Max][Max], tempLake[Max][Max];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
vector<pii> swanLocation;

int isNearWater(pii pos){
	for(int i = 0; i < 4; i++){
		int ni = pos.first + dy[i];	
		int nj = pos.second + dx[i];	
		if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		if(Lake[ni][nj] == '.' || Lake[ni][nj] == '*') return 1;
	}
	return 0;
}

void meltIce(){
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(Lake[i][j] == '*') Lake[i][j] = '.';
			if(Lake[i][j] != 'L' && isNearWater({i, j})) tempLake[i][j] = '.';
			else tempLake[i][j] = Lake[i][j];
		}
	}
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			Lake[i][j] = tempLake[i][j];
		}
	}
	Lake[swanLocation[0].first][swanLocation[0].second] = 
		Lake[swanLocation[1].first][swanLocation[1].second] = 'L';
}

void printLake(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << Lake[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int canMeet(pii start, pii end){
	cout << "check ";
	queue<pii> q;
	q.push(start);
	
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		
		if(now == end) return 1;
		
		for(int i = 0; i < 4; i++){
			int nextY = now.first + dy[i];
			int nextX = now.second + dx[i];
			if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
			if(Lake[nextY][nextX] == '*' || Lake[nextY][nextX] == 'X') continue;
			Lake[nextY][nextX] = '*';
			q.push({nextY, nextX});
		}
	}
	return 0;
}

int main(void){
	vector<pii> swanLocation;
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> Lake[i][j];
			if(Lake[i][j] == 'L') swanLocation.push_back({i, j});
		}
	}
	int answer = 0, limit = 5;	
	while(!canMeet(swanLocation[0], swanLocation[1]) && limit--){
		meltIce();
		printLake();
		answer++;	
		cout << answer << " ";
	}
	cout << answer << "\n";
	return 0;
}