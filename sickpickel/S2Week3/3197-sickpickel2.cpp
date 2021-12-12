#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int, int>

using namespace std;

int R, C;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
char Lake[Max][Max];
vector<pii> swan;

int isOutOfRange(pii pos){
    if(pos.first < 0 || pos.first >= R || pos.second < 0 || pos.second >= C)
        return 1;
    return 0;
}

int canMeet(vector<pii>& nextQueue, char visited){
    queue<pii> q;

    for(pii start : nextQueue){
        q.push(start);
        Lake[start.first][start.second] = visited;
    }
    nextQueue.clear();

    while(!q.empty()){
        pii now = q.front();
        q.pop();

        if(now == swan[1])
            { while(!q.empty()) q.pop(); return 1;}

        for(int i = 0; i < 4; i++){
            pii next = {now.first + dy[i], now.second + dx[i]};
            if(isOutOfRange(next)) continue;
            if(Lake[next.first][next.second] == visited) continue;
            if(Lake[next.first][next.second] == 'X') 
                { nextQueue.push_back(next); continue; }

            Lake[next.first][next.second] = visited;
            q.push(next);
        }

    }
    return 0;
}

int isNearWater(pii pos){
	for(int i = 0; i < 4; i++){
		int ni = pos.first + dy[i];	
		int nj = pos.second + dx[i];	
		if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		if(Lake[ni][nj] == '.' || Lake[ni][nj] == '*') return 1;
	}
	return 0;
}

void meltIce(vector<pii>& ice){
    vector<pii> temp;
    Lake[swan[0].first][swan[0].second] = 'L';
    
    for(auto it = ice.begin(); it != ice.end(); it++){
        if(isNearWater(*it)){
            temp.push_back(*it);
            ice.erase(it);
            it--;
        }
    }
    for(pii pos : temp){
        Lake[pos.first][pos.second] = '.';
    }
}

void printLake(){
    for(int i = 0; i < R; i++){
        cout << Lake[i] << "\n";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<pii> nextQueue, ice;

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Lake[i][j];
            if(Lake[i][j] == 'L') swan.push_back({i, j});
            if(Lake[i][j] == 'X'){
                ice.push_back({i, j});
            }
        }
    }

    nextQueue.push_back(swan[0]);
    int answer = 0;
    while(1){
        if(canMeet(nextQueue, '*')) break;
        meltIce(ice);
        // printLake();
        answer++;
    }
    cout << answer << "\n";
    return 0;
}