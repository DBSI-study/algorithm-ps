#include <bits/stdc++.h>
#define Max 500001

using namespace std;

int N;
int arr[Max];
long long answer = 0l;

void mergeSort(int * arr, int start, int end){
	if(start == end) return;
	
	int mid = (start + end) / 2;
	
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	
	int * copyarr = (int*)malloc(sizeof(int) * (end - start + 1));
	
	int left = start, right = mid + 1, idx = 0;

	while(left <= mid && right <= end){
		if(arr[left] > arr[right]){
			copyarr[idx++] = arr[right++];
			answer += (long long)mid - left + 1;
		}	
		else {
			copyarr[idx++] = arr[left++];
		}
	}
	
	while(left <= mid){
		copyarr[idx++] = arr[left++];
	}
 	while(right <= end){
		copyarr[idx++] = arr[right++];
	}
	
	for(int i = start; i <= end; i++){
		arr[i] = copyarr[i - start];
	}
	free(copyarr);	
}

void printArr(){
	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	mergeSort(arr, 0, N - 1);
	// printArr();
	
	cout << answer << "\n";
	return 0;
}