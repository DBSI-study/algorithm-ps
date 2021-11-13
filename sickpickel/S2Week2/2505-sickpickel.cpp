#include <bits/stdc++.h>
#define Max 10001
#define SWAP(x, y, tmp) { tmp = x; x = y; y = tmp; }

using namespace std;

void divideToGroup(vector<pair<int, int>> & group, int * arr, int size){
	int groupDiff = Max, groupBeginIdx = 0;
	for(int i = 0; i < size - 1; i++){
		int diff = arr[i] - arr[i + 1];
		if(abs(diff) == 1 && groupDiff == Max) groupDiff = diff;
		else if(groupDiff != diff) {
			group.push_back({groupBeginIdx, i});
			groupBeginIdx = i + 1;
			groupDiff = Max;
		}
	}	
	group.push_back({groupBeginIdx, size - 1});
}

void copyArr(int * from, int * to, int size){
	for(int i = 0; i < size; i++) to[i] = from[i];
}

void rotate(int begin, int end, int * toRotate){
	int tmp;
	while(begin < end){
		SWAP(toRotate[begin], toRotate[end], tmp);
		begin++; end--;
	}
}

int isSorted(int * arr, int size){
	for(int i = 0; i < size; i++){
		if(arr[i] != i + 1) return 0;
	}
	return 1;
}

int solve(vector<pair<int, int>>& answer, int * arr, int N, int cnt){

	int copyarr[Max] = {};
	vector<pair<int, int>> group;

	divideToGroup(group, arr, N);
	// pickGroupsToRotate
	for(int i = 0; i < group.size(); i++){
		for(int j = 0; j < group.size() - i; j++){
			int begin = group[j].first;
			int end = group[j + i].second;
			answer.push_back({begin, end});

			copyArr(arr, copyarr, N);
			rotate(begin, end, arr);

			if(isSorted(arr, N)) return 1;
			if(cnt == 0) if(solve(answer, arr, N, cnt + 1)) return 1;

			copyArr(copyarr, arr, N);
			answer.pop_back();
		}
	}
	return 0;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, arr[Max];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	if(isSorted(arr, N)) { cout << "1 1\n1 1\n"; return 0;}
	vector<pair<int, int>> answer;
	solve(answer, arr, N, 0);
	
	if(answer.size() == 1) answer.push_back({1, 1});
	for(auto elem : answer){
		cout << elem.first + 1 << " " << elem.second + 1 << "\n";
	}
	return 0;
}