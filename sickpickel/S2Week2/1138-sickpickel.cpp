#include <bits/stdc++.h>
#define Max 11

using namespace std;

int answer[Max];

int main(void){
	int N, LeftTallerCnt;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> LeftTallerCnt;
		for(int j = 0; j < N; j++){
			if(LeftTallerCnt == 0 && answer[j] == 0){
				answer[j] = i;
				break;
			}
			else if(answer[j] == 0) LeftTallerCnt--;
		}
	}	
	for(int i = 0; i < N; i++){
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}