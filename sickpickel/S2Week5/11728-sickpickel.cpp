#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main(void){
	int N, M;
	cin >> N >> M;
	arr.resize(N + M);	
	for(int i = 0; i < N + M; i++){
		cin >> arr[i];
	}	
	sort(arr.begin(), arr.end());
	for(auto elem : arr) cout << elem << " ";
	return 0;
}