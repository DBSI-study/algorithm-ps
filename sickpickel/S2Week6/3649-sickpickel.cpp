#include <bits/stdc++.h>
#define Max 1000001

using namespace std;

typedef long long ll;
ll legos[Max], X;

void solve(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> legos[i];
	}
	if(N == 1) {cout << "danger\n"; return; }
	X *= 10000000l;
	sort(legos, legos + N);	
	ll l1, l2, cnt;	
	for(int i = 0; i < N; i++){
		l1 = legos[i];	
		l2 = X - l1;	
		
		if(cnt = upper_bound(legos, legos + N, l2) - lower_bound(legos, legos + N, l2)) {
			if(l1 == l2 && cnt == 1) break;
			cout << "yes " << l1 << " " << l2 << "\n";
			return; 
		}
	}
	cout << "danger\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	while(cin >> X) solve();
	return 0;
}