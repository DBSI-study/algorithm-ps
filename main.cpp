#include <bits/stdc++.h>
#define Max 100001

using namespace std;

typedef long long ll;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, input;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> pq;	
	
	for(int i = 0; i < n; i++){
		cin >> input;
		pq.push(input);	
	}
	ll answer = 0;	
	while(pq.size() > 1)	{
		ll first = pq.top();
		pq.pop();
		ll second = pq.top();
		pq.pop();			
		ll sum = first + second;
		answer += sum;
		pq.push(sum);
	}
	cout << answer << "\n";
	
	return 0;
}