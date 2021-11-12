#include <bits/stdc++.h>
#define Max 1001

using namespace std;

vector<int> graph[Max];
int visited[Max];

int bfs(int start, int end){
	
	queue<pair<int, int>> q;
	q.push({start, 0});
	
	while(!q.empty()){
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		if(now == end) {
			return dist;	
		}
		
		for(int next: graph[now]){
			if(visited[next]) continue;
			visited[next] = 1;
			q.push({next, dist + 1});
		}
	}
	return -1;
}

int main(void){
	int a, b, N, M;
	cin >> a >> b >> N >> M;
	int from, to;
	for(int i = 0; i < M; i++){
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}	
	cout << bfs(a, b) << "\n";
	return 0;
}