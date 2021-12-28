// 두 백조 모두 BFS 이동하여 서로 찾기
#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int, int>

using namespace std;

int R, C;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
char Lake[Max][Max];
bool visitedWater[Max][Max], visitedSwan[Max][Max];

int isOutOfRange(pii pos){
    if(pos.first < 0 || pos.first >= R || pos.second < 0 || pos.second >= C)
        return 1;
    return 0;
}

int canMeet(vector<pii>& nextSwan, char from, char find){
	queue<pii> swan;
	for(pii elem: nextSwan) swan.push(elem);
	nextSwan.clear();	

    while(!swan.empty()){
        pii now = swan.front();
        swan.pop();
		
		// 백조의 첫 BFS 초기위치에 대한 visited 처리
		visitedSwan[now.first][now.second] = 1;	
		// 어느 방향에서 오는 백조인지를 구분하기위한 저장 
		Lake[now.first][now.second] = from;
		
        for(int i = 0; i < 4; i++){
            pii next = {now.first + dy[i], now.second + dx[i]};
            if(isOutOfRange(next)) continue;
            if(Lake[next.first][next.second] == find) return 1;
            if(visitedSwan[next.first][next.second]) continue;
			
            if(Lake[next.first][next.second] == '.') swan.push(next);
			else nextSwan.push_back(next); 
			
			visitedSwan[next.first][next.second] = 1;
        }
    }
    return 0;
}

void meltIce(vector<pii>& nextWater){
	
	queue<pii> water;
	for(pii elem: nextWater) water.push(elem);
	nextWater.clear();
	
	
	while(!water.empty()){
		pii now = water.front();
		water.pop();
		
		// water의 첫 BFS 초기위치에 대한 visited 처리
		visitedWater[now.first][now.second] = 1;
		
		if(Lake[now.first][now.second] == 'X'){
			Lake[now.first][now.second] = '.';
		}
		
		for(int i = 0; i < 4; i++){
			pii next = { now.first + dy[i], now.second + dx[i] };
			if(isOutOfRange(next)) continue;
			if(visitedWater[next.first][next.second]) continue;
			if(Lake[next.first][next.second] == 'X') nextWater.push_back(next);
			else water.push(next);
			
			visitedWater[next.first][next.second] = 1;
		}
	}
}

void printLake(){
    for(int i = 0; i < R; i++){
        cout << Lake[i] << "\n";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	vector<pii> nextWater, nextSwan1, nextSwan2;
	
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Lake[i][j];
            if(Lake[i][j] == 'L') {
				if(nextSwan1.empty()) nextSwan1.push_back({i, j});
				else { nextSwan2.push_back({i, j}); Lake[i][j] = '^'; }
			}
			if(Lake[i][j] != 'X') nextWater.push_back({i, j});
        }
    }

    int answer = 0;
	meltIce(nextWater);
		
	while(1){
		// 한쪽에서 만나지 못한다면
		if(canMeet(nextSwan1, '*', '^')) break;
		// 반대쪽도 이동가능한 범위까지 이동
		if(canMeet(nextSwan2, '^', '*')) break;
		// 얼음 녹이기
		meltIce(nextWater);
		answer++;
	}
	// printLake();
    cout << answer << "\n";
    return 0;
}