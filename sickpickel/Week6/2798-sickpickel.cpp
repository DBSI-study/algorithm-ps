#include <bits/stdc++.h>
#define Max 100

using namespace std;

int arr[Max];

int main(void){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	int answer = 0;	
	for(int i = 0; i < N - 2; i++){
		for(int j = i + 1; j < N - 1; j++){
			for(int k = j + 1; k < N; k++){
				int num = arr[i] + arr[j] + arr[k];
				if(num > M) continue;
				answer = max(answer, num);
			}
		}
	}
	cout << answer << "\n";
	return 0;
}