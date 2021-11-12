#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	int N, input;
	cin >> N;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < N; i++){
		cin >> input;
		pq.push(input);
	}
	int answer = 0;	
	while(pq.size() != 1){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		answer += first + second;	
		pq.push(first + second);
	}
	pq.pop();
	cout << answer << "\n";
	return 0;
}