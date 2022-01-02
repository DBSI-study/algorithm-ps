// 모든 노드 처음 BFS 돌면서 그룹구분해주고
// 얼음 녹이면서 백조 그룹끼리 붙었는지만 확인.
#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 1501

using namespace std;

typedef bool(*parr)[Max];
typedef char Data;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int R, C;
Data Lake[Max][Max];
int root[Max * Max + 1];
vector<pii> swan;

int getValue(pii a){
	return Lake[a.first][a.second];
}

void setValue(pii a, Data data){
	Lake[a.first][a.second] = data;	
}

int isOutofRange(pii a){
	if(a.first < 0 || a.first >= R || a.second < 0 || a.second >= C)
		return 1;
	return 0;
}

int toLinear(pii x){
	return x.first * C + x.second;
}

int find(int x){
	if(x == root[x]) return x;
	return root[x] = find(root[x]);
}

void unify(pii xx, pii yy){
	int x = find(toLinear(xx));
	int y = find(toLinear(yy));
	
	if(x < y) root[x] = y;
	else root[y] = x;
}

void setGroup(pii start, parr visited){
	queue<pii> q;
	q.push(start);
	visited[start.first][start.second] = 1;
	
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			pii next = { now.first + dy[i], now.second + dx[i] };
			if(isOutofRange(next)) continue;
			if(visited[next.first][next.second]) continue;
			if(getValue(next) == 'X') continue;
			visited[next.first][next.second] = 1;
			unify(now, next);
			q.push(next);
		}
	}
}

void divideLake(){
	bool visited[Max][Max] = {};	
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(visited[i][j] || getValue({i, j}) == 'X') continue;
			setGroup({i, j}, visited);
		}
	}	
}

// 얼음을 녹이는 동시 두개의 백조가 서로 같은 그룹에 속하게 되는지 확인한다.
int meltIce(queue<pair<pii, pii>>& nextQueue, parr visited){
	queue<pair<pii, pii>> water = nextQueue;
	while(!nextQueue.empty()) nextQueue.pop();
	
	while(!water.empty()){
		pii now = water.front().first;
		pii from = water.front().second;
		water.pop();
		
		if(getValue(now) == 'X'){
			setValue(now, '.');
			unify(now, from);
		}
		for(int i = 0; i < 4; i++){
			pii next = { now.first + dy[i], now.second + dx[i] };
			if(isOutofRange(next)) continue;
			if(getValue(next) != 'X'){
				if(find(toLinear(now)) != find(toLinear(next))) unify(now, next);
				if(find(toLinear(swan[0])) == find(toLinear(swan[1]))) return 1;
			}
			if(visited[next.first][next.second]) continue;
			
			if(getValue(next) != 'X') water.push({next, from});
			else nextQueue.push({next, now});
			
			visited[next.first][next.second] = 1;	
		}
	}
	return 0;
}

void printGroup(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << find(i * C + j) << " " ;
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	
	queue<pair<pii, pii>> nextQueue;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> Lake[i][j];
			if(getValue({i, j}) == 'L') swan.push_back({i, j});
			if(getValue({i, j}) != 'X') nextQueue.push({{i, j},{i, j}});
			root[i * C + j] = i * C + j;
		}
	}
	
	int answer = 0;	
	bool waterVisited[Max][Max] = {};
	
	divideLake();
	while(!meltIce(nextQueue, waterVisited)){
		// printGroup();
		answer++;
	}
	cout << answer << "\n";	
	return 0;
}