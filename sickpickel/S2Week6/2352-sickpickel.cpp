#include <bits/stdc++.h>
#define Max 40001

using namespace std;

int port[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> port[i];
	}
	vector<int> store;
	store.push_back(0);
	
	for(int i = 0; i < N; i++){
		if(store.back() < port[i])	{
			store.push_back(port[i]);
		}
		else {
			int idx = lower_bound(store.begin(), store.end(), port[i]) - store.begin();
			store[idx] = port[i];
		}
	}
	cout << store.size() - 1 << "\n";	
	return 0;
}