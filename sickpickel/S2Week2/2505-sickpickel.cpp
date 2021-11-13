#include <bits/stdc++.h>
#define Max 10001
#define SWAP(x, y, tmp) { tmp = x; x = y; y = tmp; }

using namespace std;

int isSorted(int * arr, int begin, int end){
	for(int i = begin; i < end; i++){
		if(arr[i] != i + 1) return 0;
	}
	return 1;
}
void divideToGroup(vector<pair<int, int>> & group, int * arr, int size){
	int groupDiff = Max, groupBeginIdx = 0;
	for(int i = 0; i < size - 1; i++){
		int diff = arr[i] - arr[i + 1];
		if(abs(diff) == 1 && groupDiff == Max) groupDiff = diff;
		else if(groupDiff != diff) {
			if(!isSorted(arr, 0, i + 1)) group.push_back({groupBeginIdx, i});
			groupBeginIdx = i + 1;
			groupDiff = Max;
		}
	}	
	if(!isSorted(arr, groupBeginIdx, size)) 
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
int solve(vector<pair<int, int>>& answer, int * arr, int N, int cnt){

	int copyarr[Max] = {};
	vector<pair<int, int>> group;

	divideToGroup(group, arr, N);
	if(group.size() == 2){
		for(int i = 0; i < group.size(); i++){
			int start = group[i].first, end = group[i].second;
			if(start - end == -1){
				group.push_back({start, start});
				group.push_back({end, end});
				group.erase(group.begin() + i);
			}
		}	
	}
	// pickGroupsToRotate
	for(int i = 0; i < group.size(); i++){
		for(int j = 0; j < group.size() - i; j++){
			int begin = group[j].first;
			int end = group[j + i].second;
			answer.push_back({begin, end});

			copyArr(arr, copyarr, N);
			rotate(begin, end, arr);

			if(isSorted(arr, 0, N)) return 1;
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
	if(isSorted(arr, 0, N)) { cout << "1 1\n1 1\n"; return 0;}
	vector<pair<int, int>> answer;
	solve(answer, arr, N, 0);
	
	if(answer.size() == 1) answer.push_back({1, 1});
	for(auto elem : answer){
		cout << elem.first + 1 << " " << elem.second + 1 << "\n";
	}
	return 0;
}