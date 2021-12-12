#include <bits/stdc++.h>
#define Max 10001

using namespace std;

vector<int> connection[Max];
int N, M;
int visited[Max];

int countHackables(int now){
	int ret = 1;
	visited[now] = 1;
	
	for(int next : connection[now]){
		if(visited[next]) continue;
		ret += countHackables(next);
	}
	return ret;
}

int main(void){
	int A, B;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		connection[B].push_back(A);
	}
	int save_max = 0, saveCnt[Max];	
	for(int i = 1; i <= N; i++){
		int hackables = countHackables(i);
		
		save_max = max(save_max, hackables);
		saveCnt[i] = hackables;	
		
		for(int i = 1; i <= N; i++) visited[i] = 0;
	}
	for(int i = 1; i <= N; i++){
		if(save_max == saveCnt[i]) cout << i << " ";
	}
	return 0;
}