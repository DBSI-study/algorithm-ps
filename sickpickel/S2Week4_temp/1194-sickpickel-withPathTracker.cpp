// 이 지점을 어떤 키들로 방문했었는지 visited[y][x] 안에 비트마스킹 하여 저장
// 현재 가지고 있는 키와 대조해보았을 때 모두 포함한다면 continue,
// 하나라도 새로운 키를 가지고 있다면 visited 업데이트 후 진행.

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

void printKeys(int keys){
	cout << "collected keys : ";
	char idx = 'a';
	keys /= 2;
	while(keys)	{
		if(keys % 2) cout << idx << " ";
		keys /= 2;
		idx++;
	}
	cout << "\n";
}

void printPath(vector<pii>& path){
	int idx = 0;
	for(pii elem : path){
		cout << "#" << idx++ << " ";
		cout << "(" << elem.first << ", " << elem.second << ")\n";
	}
	cout << "\n";
}

int bfs(pii start){
	
	int visited[Max][Max] = {};
	queue<pair<pair<pii, pii>, vector<pii>>> q;
	vector<pii> begin;
	begin.push_back(start);
	q.push({{start, {1, 0}}, begin});
	visited[start.first][start.second] = 1;
	
	while(!q.empty()){

		pii now = q.front().first.first;	
		int keys = q.front().first.second.first;
		int distance = q.front().first.second.second;
		vector<pii> path = q.front().second;
		q.pop();	
		
		if(getValue(now) == '1') {
			printKeys(keys);
			printPath(path);
			return distance;
		}
	
		for(int i = 0; i < 4; i++){
			int nextKeys = keys;
			pii next = { now.first + dy[i], now.second + dx[i] };
			
			// 다음이 갈 수 없는 곳
			if(outOfRange(next) || getValue(next) == '#') continue;
			// 다음이 키가 없는 문	
			if(isupper(getValue(next)) && (keys & (1 << getValue(next) - 'A' + 1)) == 0) continue;
			// 현재 키를 포함한 상태에서 다음을 방문했던 경우	
			if((visited[next.first][next.second] & keys) == keys) continue;
			// 다음 장소에 키가 있는 경우	
			if(islower(getValue(next))) nextKeys |= (1 << getValue(next) - 'a' + 1);
			
			visited[next.first][next.second] = keys;
			
			path.push_back(next);
			q.push({{next, {nextKeys, distance + 1}}, path});
			path.pop_back();
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
	
	cout << bfs(start) << "\n";
	return 0;
}