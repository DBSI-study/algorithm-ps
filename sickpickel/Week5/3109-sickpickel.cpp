// 빵 집
#include <bits/stdc++.h>

using namespace std;

int R, C;
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };
char street[10000][501];

int dfs(int nowI, int nowJ){
	street[nowI][nowJ] = 'x';
	if(nowJ == C - 1){
		return 1;
	}
	for(int i = 0; i < 3; i++){
		int nextI = nowI + dy[i];
		int nextJ = nowJ + dx[i];
		if(nextI < 0 || nextI >= R) continue;
		if(street[nextI][nextJ] == 'x') continue;
		if(dfs(nextI, nextJ)) return 1;
	}
	return 0;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> R >> C;
	for(int i = 0; i < R; i++) cin >> street[i];
	
	int answer = 0;	
	for(int i = 0; i < R; i++) answer += dfs(i, 0);
	cout << answer << "\n";	
	return 0;
}