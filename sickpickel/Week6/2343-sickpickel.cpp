// 기타레슨
#include <bits/stdc++.h>
#define Max 100001
#define INF 987654321234

using namespace std;

typedef long long ll;

ll lecture[Max];

int main(void){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> lecture[i];
	}	
	ll answer = INF;
	ll left = 0, right = 100000 * 10000;
	while(left <= right){	
		int flag = 0;
		ll mid = (left + right) / 2;
		cout << mid << " ";
		int blueRayCnt = 1, storage = 0;
		for(int i = 0; i < N; i++){
			if(lecture[i] > mid) { flag = 1; break; }
			if(storage + lecture[i] > mid) { blueRayCnt++; storage = 0; }
			storage += lecture[i];	
		}
		
		if(blueRayCnt > M || flag){
			left = mid + 1;	
		}
		else{
			right = mid - 1;
		}
		
	}
	cout << answer << "\n";
	return 0;
}