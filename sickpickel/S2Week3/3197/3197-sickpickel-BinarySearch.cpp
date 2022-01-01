// bfs로 2차원 배열에 얼음들 몇일 뒤에 녹는지 저장
// 최대 걸리는 일이랑 0일 사이에서 이진탐색
// 백조의 이동은 현재 이진탐색에서의 최대 일수로 이동가능한 부분까지
// 큐 2개써서 푸는 방법 이용해서 백조 이동 실패했을 때 다음 출발선 앞당겨서 할 수 있을듯.


#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int, int>

using namespace std;

int N, M;
char Lake[Max][Max];
int times[Max][Max];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

char getValue(pii a){
	return Lake[a.first][a.second];
}

int isOutofRange(pii a){
	if(a.first < 0 || a.first >= N || a.second < 0 || a.second >= M)
		return 1;
	return 0;
}

int initTimes(vector<pii>& start){
	int ret = 0;
	queue<pair<pii, int>> q;
	for(pii elem : start) {
		q.push({elem, 0});
		times[elem.first][elem.second] = 1;
	}

	while(!q.empty()){ 
		pii now = q.front().first;
		int days = q.front().second;
		int nextDays;
		q.pop();
		
		ret = max(ret, days);
		
		for(int i = 0; i < 4; i++){
			pii next = {now.first + dy[i], now.second + dx[i]};
			if(isOutofRange(next) || times[next.first][next.second] >= 0) continue;
			if(getValue(next) == 'X') nextDays = days + 1;
			else nextDays = 0;
			
			times[next.first][next.second] = nextDays;
			q.push({next, nextDays});
		}
	}
	return ret;
}

int canMeet(queue<pii>& nextQueue, int maxDay){

	bool visited[Max][Max] = {};
	
	queue<pii> q = nextQueue;
	while(!nextQueue.empty()) nextQueue.pop();
	
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		
		if(getValue(now) == 'L') return 1;
		
		for(int i = 0; i < 4; i++){
			pii next = {now.first + dy[i], now.second + dx[i]};
			if(isOutofRange(next) || visited[next.first][next.second]) continue;
			if(times[next.first][next.second] > maxDay)	nextQueue.push(next);
			else q.push(next);
			
			visited[next.first][next.second] = 1;
		}
	}
	return 0;
}

void printTimes(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << times[i][j] << " ";
		}
		cout << "\n";		
	}
	cout << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	pii swan;
	vector<pii> water;
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Lake[i][j];
			if(Lake[i][j]=='L') swan = {i, j};
			if(Lake[i][j] != 'X') water.push_back({i, j});
			times[i][j] = -1;
		}
	}
	
	Lake[swan.first][swan.second] = 's';
	
	int save_max = initTimes(water);
	int left = 0, right = save_max;
	int answer = 0;	
	
	// printTimes();
	
	queue<pii> nextQueue;
	nextQueue.push(swan);
	
	while(left <= right){
		int mid = (left + right) / 2;
		if(canMeet(nextQueue, mid)){
			answer = mid;
			right = mid - 1;
			// 더 적은 정답을 위해 다음 검사때는 아예 처음시작부터
			while(!nextQueue.empty()) nextQueue.pop();
			nextQueue.push(swan);
		}
		else {
			// 다음에 다시 탐색을 해야 하는 경우 이번에 막힌곳부터
			left = mid + 1;
		}
	}
	cout << answer << "\n";
	return 0;
}