#include <bits/stdc++.h>

using namespace std;

vector<int> note1;

void solve(){
	int N, M;
	cin >> N;
	note1.resize(N);
	for(int i = 0; i < N; i++){
		cin >> note1[i];	
	}
	sort(note1.begin(), note1.end());
	cin >> M;
	int note2;	
	for(int i = 0; i < M; i++){
		cin >> note2;
		if(binary_search(note1.begin(), note1.end(), note2)) cout << "1\n";
		else cout << "0\n";
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}