#include <bits/stdc++.h>
#define Max 500001 

using namespace std;

int N;
vector<int> arr[Max];

int countAllSteps(){
	int ret = 0;	
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {-1, 1}});
	
	while(!q.empty()){
		int dist = q.front().first;
		int now = q.front().second.second;
		int from = q.front().second.first;
		q.pop();
		
		for(int next: arr[now]){
			if(next == from) continue;
			q.push({dist + 1, {now, next}});
		}
		if(arr[now].size() == 1){
			ret += dist;	
		}
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;
	int a, b;
	for(int i = 0; i < N - 1; i++){
		cin >> a >> b;	
		arr[a].push_back(b);
		arr[b].push_back(a);
	}	
	
	int allsteps = countAllSteps();
	if(allsteps % 2 == 0) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}