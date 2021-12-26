// 이 지점을 어떤 키들로 방문했었는지 visited[y][x] 안에 비트마스킹 하여 저장
// 현재 가지고 있는 키와 대조해보았을 때 모두 포함한다면 continue,
// 하나라도 새로운 키를 가지고 있다면 visited 업데이트 후 진행.
#include <bits/stdc++.h>
#define Max 51

using namespace std;

int N, M;
char maze[Max][Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> maze[i][j];
			
		}
	}
	
	
		
	
	return 0;
}