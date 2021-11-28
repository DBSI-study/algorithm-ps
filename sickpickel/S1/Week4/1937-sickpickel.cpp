#include <bits/stdc++.h>
#define Max 501

using namespace std;

// dp[Max][Max] 에는 해당하는 위치에서 시작했을 때 판다가 최대한 이동할 수 있는 거리 저장
int dp[Max][Max];

int N, forest[Max][Max];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int go(int Y, int X){
	
	int& ref = dp[Y][X];
	if(ref != 0) return ref;
	ref = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = Y + dy[i];
		int nx = X + dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;	
		if(forest[ny][nx] <= forest[Y][X]) continue;
		
		ref = max(ref, go(ny, nx) + 1);
	}
	return ref;	
}

int main(void){
	ios::sync_with_stdio(false);cin.tie(NULL);
		
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> forest[i][j];
		}
	}
	int answer = 0;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			answer = max(answer, go(i, j));
		}
	}
		
	cout << answer << "\n";	
	return 0;
}