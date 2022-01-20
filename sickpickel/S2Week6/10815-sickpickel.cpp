#include <bits/stdc++.h>
#define Max 500001

using namespace std;

int arr[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	int N, M, query;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;	
	for(int i = 0; i < M; i++){
		cin >> query;
		if(binary_search(arr, arr + N, query)) cout << "1 ";
		else cout << "0 ";
	}
	return 0;
}