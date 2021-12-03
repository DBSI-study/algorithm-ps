// 바이러스
#include <bits/stdc++.h>
#define Max 101

using namespace std;

vector<int> connection[Max];

int InfectFrom(int start){
	int ret = 0, visited[Max] = {};
	queue<int> q;
	q.push(start);
	visited[start] = 1;	
	while(!q.empty()){
		ret++;
		int now = q.front();
		q.pop();
		
		for(auto next : connection[now]){
			if(visited[next]) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
	return ret - 1;
}

int main(void){
	int N, pairCnt, from, to;
	cin >> N >> pairCnt;
		
	for(int i = 0; i < pairCnt; i++){
		cin >> from >> to;
		connection[from].push_back(to);
		connection[to].push_back(from);
	}
	cout << InfectFrom(1) << "\n";
	return 0;
}