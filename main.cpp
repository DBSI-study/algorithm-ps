#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 10

using namespace std;

typedef int (*parr)[Max];

vector<pii> emptyPos;
vector<pii> virusPos;
vector<pii> newWall;

int N, M, answer = 0;
int ddy[8] = { 1, -1, 0 ,0, 1, -1, 1, -1 };
int ddx[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int nearWall(parr arr, int y, int x){
	for(int i = 0; i < 8; i++){
		int ny = y + ddy[i], nx = x + ddx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M) return 1;
		if(arr[ny][nx] == 1) return 1;
	}
	return 0;
}

int go(parr arr){
	int flag = 0;	
	int safeCount = emptyPos.size() - 3;	
	
	for(pii elem : newWall){
		int y = elem.first; int x = elem.second;
		if(!nearWall(arr, y, x)) flag++;
	}
	if(flag == 3) return 0;	

	int visited[Max][Max] = {};
	queue<pii> q;
	
	for(pii elem : virusPos){
		q.push(elem);
	}
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)	{
			int ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if(!visited[ny][nx] && arr[ny][nx] == 0) {
				safeCount--;
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
	return safeCount;
}

void backtracking(parr arr, int now, int cnt){
	
	if(cnt == 3){
		answer = max(answer, go(arr));		
		return;
	}
		
	for(int i = now, lim = emptyPos.size(); i < lim; i++){
		int y = emptyPos[i].first, x = emptyPos[i].second;	
		arr[y][x] = 1;
		newWall.push_back({y, x});
		backtracking(arr, i + 1, cnt + 1);	
		newWall.pop_back();
		arr[y][x] = 0;
	}	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int arr[Max][Max];
	cin >> N >> M;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 0) emptyPos.push_back({i, j});
			else if(arr[i][j] == 2) virusPos.push_back({i, j});
		}	
	}
	
	backtracking(arr, 0, 0);
	cout << answer << "\n";	
	return 0;
}