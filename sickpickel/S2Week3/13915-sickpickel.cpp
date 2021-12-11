#include <bits/stdc++.h>
#define Max 100001

using namespace std;

int getNext(int now, int move){
	if(move == 0) return now - 1;
	if(move == 1) return now + 1;
	if(move == 2) return now * 2;
	return -1;
}

void bfs(int start, int end){
	bool visited[Max] = {};	
	int path[Max] = {};
	
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = true;
	path[start] = -1;
	
	while(!q.empty()){
		int now = q.front().first;
		int distance = q.front().second;
		
		q.pop();
		
		if(now == end){
			cout << distance << "\n";
			
			vector<int> track;
			while(now != -1){
				track.push_back(now);
				now = path[now];	
			}
			reverse(track.begin(), track.end());
			for(int elem : track) cout << elem << " ";
			return;
		}
		
		for(int i = 0; i < 3; i++){
			int next = getNext(now, i);
			if(next < 0 || next >= Max) continue;
			if(visited[next]) continue;
			visited[next] = true;
			path[next] = now;
				
			q.push({next, distance + 1});
		}	
	}
}

int main(void){
	ios::sync_with_stdio(false); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	
	bfs(N, K);
	
	return 0;
}