#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 100001

using namespace std;

int root[Max];
vector<pair<pii, int>> logs;

int find(int x){
	if(x == root[x]) return x;
	return root[x] = find(root[x]);
}

void unify(int x, int y){
	x = find(x);
	y = find(y);
	if(x < y) root[y] = x;
	else root[x] = y;
}

bool compare(pair<pii, int> A, pair<pii, int> B){
	pii a = A.first, b = B.first;	
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, Q, x1, x2, y;
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> x1 >> x2 >> y;
		logs.push_back({{x1, x2}, i});
		root[i] = i;
	}
	// 모든 통나무들에 대해서 유파로 그룹화.
	sort(logs.begin(), logs.end(), compare);
	pair<pii, int> now, next;
	now = logs[0];
	for(int i = 0; i < N - 1; i++){
		next = logs[i + 1];
		
		if(next.first.first <= now.first.second)
			unify(now.second, next.second);
		if(next.first.second > now.first.second) now = next;
	}
	
	int start, end;	
	for(int i = 0; i < Q; i++){
		cin >> start >> end;
		start--; end--;
		if(find(start) == find(end)) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}