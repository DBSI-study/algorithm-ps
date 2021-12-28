#include <bits/stdc++.h>
#define Max 1501
#define pii pair<int,int>

using namespace std;

int R, C;
char Lake[Max][Max], tempLake[Max][Max];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
vector<pii> swanLocation, ice, nextQueue;

// ice vector에 저장되어 있는 얼음 중 녹일 수 있는 것
void meltIce(){
	
}

// bfs로 탐색
int canMeet(){
	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> Lake[i][j];
			if(Lake[i][j] == 'L') swanLocation.push_back({i, j});
			else if(Lake[i][j] == 'X') ice.push_back({i, j});
		}
	}
	int answer = 0;	
	while(!canMeet()){
		meltIce();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}