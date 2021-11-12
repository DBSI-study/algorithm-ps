#include <bits/stdc++.h>
#define INF 51

using namespace std;

typedef long long ll;

ll side[7];

int sidecomb[12][2] = {{1, 3}, {1, 2}, {1, 5}, {1, 4}, {2, 3}, {3, 5}, {5, 4}, {2, 4}, {6, 3}, {6, 5}, {6, 2}, {6, 4}};
int cornercomb[8][3] = { {1, 2, 3}, {1, 3, 5}, {1, 5, 4}, {1, 4, 2}, {6, 2, 4}, {6, 3, 2
}, {6, 3, 5}, {6, 5, 4}};

int main(void){
	ll N, answer = 0l;
	cin >> N;
	
	ll min1 = INF, min2 = INF * 2, min3 = INF * 3;
	for(int i = 1; i <= 6; i++){
		cin >> side[i];
		min1 = min(min1, side[i]);
	}
	if(N == 1){
		sort(side + 1, side + 7);
		for(int i = 1; i < 6; i++) answer += side[i];
		cout << answer << "\n"; return 0;
	}
	
	for(int i = 0; i < 12; i++){
		min2 = min(min2, side[sidecomb[i][0]] + side[sidecomb[i][1]]);
	}	
	for(int i = 0; i < 8; i++){
		min3 = min(min3, side[cornercomb[i][0]] + side[cornercomb[i][1]] + side[cornercomb[i][2]]);
	}
		
	answer += min1 * ((N - 2) * (N - 2) * 5 + (N - 2) * 4);
	answer += min2 * ((N - 2) * 8 + 4);
	answer += min3 * 4;
	cout << answer << "\n";
	return 0;
}}