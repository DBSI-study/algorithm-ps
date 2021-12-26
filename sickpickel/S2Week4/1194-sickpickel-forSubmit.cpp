#include <bits/stdc++.h>
#define Max 51
#define pii pair<int, int>

using namespace std;

int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char maze[Max][Max];

int outOfRange(pii a){
	if(a.first < 0 || a.first >= N || a.second < 0 || a.second >= M)
		return 1;
	return 0;
}

char getValue(pii a){
	return maze[a.first][a.second];
}

int getShortestPathLen(pii start){
	
	int visited[Max][Max] = {};
	queue<pair<pii, pii>> q;
	q.push({start, {1, 0}});
	visited[start.first][start.second] = 1;
	
	while(!q.empty()){
		pii now = q.front().first;	
		int keys = q.front().second.first;
		int distance = q.front().second.second;
		q.pop();	
		
		if(getValue(now) == '1') return distance;
		
		for(int i = 0; i < 4; i++){
			int nextKeys = keys;		
			pii next = { now.first + dy[i], now.second + dx[i] };
			// 다음이 갈 수 없는 곳
			if(outOfRange(next) || getValue(next) == '#') continue;
			// 다음이 키가 없는 문	
			if(isupper(getValue(next)) && (keys & (1 << getValue(next) - 'A' + 1)) == 0) continue;
			// 현재 키를 포함한 상태에서 다음을 방문했던 경우	
			if((visited[next.first][next.second] & keys) == keys) continue;
			// 다음 위치에서 키 획득	
			if(islower(getValue(next))) nextKeys |= (1 << getValue(next) - 'a' + 1);
			
			visited[next.first][next.second] = keys;
			q.push({next, {nextKeys, distance + 1}});
		}
	}
	return -1;
}


int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	pii start;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> maze[i][j];
			if(maze[i][j] == '0') start = { i, j };
		}
	}
	
	cout << getShortestPathLen(start) << "\n";
	return 0;
}