#include <bits/stdc++.h>
#define Max 301

using namespace std;

typedef int (*parr)[Max];

int N, M, ground[Max][Max];
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };


int countNeighboringSea(int i, int j){
	int ret = 0;
	for(int k = 0; k < 4; k++){
		int ni = i + di[k];
		int nj = j + dj[k];
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		if(ground[ni][nj] == 0) ret++;
	}
	return ret;
}

void meltIceBurg(){
	int newMap[Max][Max] = {};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			newMap[i][j] = max(0, ground[i][j] - countNeighboringSea(i, j));	
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			ground[i][j] = newMap[i][j];
		}
	}
}

void dfs(int i, int j, parr visited){
	visited[i][j] = 1;
	for(int k = 0; k < 4; k++){
		int ni = i + di[k];
		int nj = j + dj[k];
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;	
		if(visited[ni][nj] || !ground[ni][nj]) continue;
		dfs(ni, nj, visited);	
	}	
}

int countIceBurgChunk(){
	int ret = 0, visited[Max][Max] = {};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(visited[i][j] || !ground[i][j]) continue;
			dfs(i, j, visited);	
			ret++;
		}
	}
	return ret;
}

void printMap(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) {
			cout << ground[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int spendYear(){
	meltIceBurg();	
	return countIceBurgChunk();
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> ground[i][j];
		}
	}
	int answer = 1, chunkCount;
	while((chunkCount = spendYear()) < 2){
		if(chunkCount == 0) {cout << "0\n"; return 0;}
		answer++;
	}
	cout << answer << "\n";
	return 0;
}