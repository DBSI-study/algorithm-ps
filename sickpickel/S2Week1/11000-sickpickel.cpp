// 강의실 정렬 우선순위 
// 시작시간 이른, 종료시간 늦은 순서 정렬
#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	
	int N, start, end;
	cin >> N;
	vector<pair<int, int>> lectures(N);
	priority_queue<int, vector<int>, greater<int>> roomEndTime;
	for(int i = 0 ; i < N; i++)	{
		cin >> start >> end;
		lectures[i] = {start, -end};
	}
	sort(lectures.begin(), lectures.end());
	
	for(auto lecture : lectures){
		if(roomEndTime.size() && roomEndTime.top() <= lecture.first)
			roomEndTime.pop();
		roomEndTime.emplace(-lecture.second);
	}
	cout << roomEndTime.size() << "\n";
	return 0;
}