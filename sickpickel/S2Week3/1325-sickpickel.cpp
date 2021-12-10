// 효율적인 해킹

#include <bits/stdc++.h>
#define Max 10001

using namespace std;

vector<int> connection[Max];
vector<int> cycleHead;
int memoization[Max], root[Max];

int visited[Max];

int N, M, A, B;

void init(int * arr, int start, int end, int value){
	for(int i = start; i < end; i++) arr[i] = value;
}

int find(int x){
	if(x == root[x]) return x;
	return root[x] = find(root[x]);
}

void unify(int x, int y){
	x = find(x);
	y = find(y);
	root[y] = x;
}

void updateMemoization(int now, int value){
	// cout << "update : " << now << " " << value << "\n";
	int pivot = find(now);
	for(int i = 1; i <= N; i++){
		if(pivot == find(i)){
			memoization[i] = value;
		}
	}	
}

int countHackables(int now){
	
	visited[now] = 1;
	
	int &ref = memoization[now];
	if(ref != 0) return ref;
	
	int save = 1;
	for(int next : connection[now]){
		if(visited[next]){
			if(memoization[next] == 0) { 
				visited[next] = 2;
				cycleHead.push_back(next);
			}
		}	
		else save += countHackables(next);
		
		if(cycleHead.size() && visited[next] == 2) {
			visited[now] = 2;
			unify(next, now);
		}
	}
	ref = save;	
	if(cycleHead.size() && now == cycleHead.back()){
		cycleHead.pop_back();
		updateMemoization(now, ref);	
	}
	// 이번 노드 탐색을 완료하는 시점에서 처리
	return ref;
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		connection[B].push_back(A);
	}	
	
	for(int i = 1; i <= N; i++) root[i] = i;
	
	int save_max = 0;
	for(int i = 1; i <= N; i++){
		save_max = max(save_max, countHackables(i));
		// cout << i << " " << countHackables(i) << "\n";
		init(visited, 1, N + 1, 0);
	}
	
	for(int i = 1; i <= N; i++){
		if(save_max == countHackables(i)) cout << i << " ";
	}
	return 0;
}