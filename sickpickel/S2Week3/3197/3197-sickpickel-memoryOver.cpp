#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int, int>

using namespace std;

int R, C;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
char Lake[Max][Max];
bool visitedWater[Max][Max];
queue<pii> water, nextWater, swan, nextSwan;

int isOutOfRange(pii pos){
    if(pos.first < 0 || pos.first >= R || pos.second < 0 || pos.second >= C)
        return 1;
    return 0;
}

int canMeet(char visited, char find){
	swan = nextSwan;
	while(!nextSwan.empty()) nextSwan.pop();

    while(!swan.empty()){
        pii now = swan.front();
        swan.pop();

        for(int i = 0; i < 4; i++){
            pii next = {now.first + dy[i], now.second + dx[i]};
            if(isOutOfRange(next)) continue;
            if(Lake[next.first][next.second] == visited) continue;
            if(Lake[next.first][next.second] == find) 
			{ while(!swan.empty()) swan.pop(); return 1; }
			
            if(Lake[next.first][next.second] == 'X') 
                {nextSwan.push(next); continue;}

            Lake[next.first][next.second] = visited;
            swan.push(next);
        }
    }
    return 0;
}

void meltIce(){
	
	water = nextWater;
	while(!nextWater.empty()) nextWater.pop();
	
	while(!water.empty()){
		pii now = water.front();
		water.pop();
		
		if(Lake[now.first][now.second] == 'X'){
			Lake[now.first][now.second] = '.';
		}
		
		for(int i = 0; i < 4; i++){
			pii next = { now.first + dy[i], now.second + dx[i] };
			if(isOutOfRange(next)) continue;
			if(visitedWater[next.first][next.second]) continue;
			if(Lake[next.first][next.second] == 'X') nextWater.push(next);
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
	vector<pii> swan;

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Lake[i][j];
            if(Lake[i][j] == 'L') swan.push_back({i, j});
			if(Lake[i][j] != 'X') nextWater.push({i, j});
        }
    }
	if(R == 1 && C == 1) { cout << "0\n"; return 0; }
    nextSwan.push(swan[0]);
	Lake[swan[1].first][swan[1].second] = '^';
	
    int answer = 0;
	meltIce();
    while(1){
        if(canMeet('*', '^')) break;
        meltIce();
        answer++;
    }
	// printLake();
    cout << answer << "\n";
    return 0;
}