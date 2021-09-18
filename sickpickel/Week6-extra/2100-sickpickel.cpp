#include <bits/stdc++.h>
#define ld long double
#define pdd pair<ld, ld>
#define DINF 987654321l

using namespace std;

int N;
string chimney;
int visited[26][100];
vector<pdd> pos[26], answer;

pdd getNewRange(pdd before, pdd now, pdd range){
	ld a = (before.second - now.second);
	if (before.first != now.first) a /= (before.first - now.first);
	if(a == 0){
		if(before.first > now.first) return {1l, -1l};
		return range;
	}
	ld x_intersept = now.first - now.second * (now.first - before.first) / (now.second - before.second);
	pdd temprange;
	// cout << "now : " << now.first << " " << now.second << " / ";
	// cout << "before : " << before.first << " " << before.second << " / ";
	// cout << "a : " << a << " / ";
	if(now.first > before.first) {
		if(a > 0) temprange = {x_intersept, DINF};
		else temprange = {-DINF, x_intersept};
	}
	else if(now.first < before.first){
		if(a < 0) temprange = {x_intersept, DINF};
		else temprange = {-DINF, x_intersept};		
	}
	else {
		if(before.second > now.second) temprange = {-DINF, x_intersept};
		else temprange = {x_intersept, DINF};
	}
	
	pdd ret;
	ret.first = (range.first > temprange.first ? range.first : temprange.first);
	ret.second = (range.second < temprange.second ? range.second : temprange.second);
	return ret;
}

void backtracking(int cnt, pdd before, pdd range){
	// cout << cnt << " " << chimney[cnt] << " ";
	if(cnt == chimney.size()){
		answer.push_back(range);
		return;
	}
	for(int i = 0; i < pos[chimney[cnt] - 'A'].size(); i++){
		int idx = chimney[cnt] - 'A';
		if(visited[idx][i]) continue;
		// 절편구해서 range 비교, 새로운 range 전달.
		pdd newrange = getNewRange(before, pos[idx][i], range);	
		// cout << "(" << newrange.first <<  ", " << newrange.second << ")" << "\n";
		if(newrange.first >= newrange.second) continue;
		
		visited[idx][i] = 1;
		backtracking(cnt + 1, pos[idx][i], newrange);
		visited[idx][i] = 0;
	}	
}

int main(void){

	cin >> N >> chimney;
	char shape;
	ld x, y;
	for(int i = 0; i < N; i++){
		cin >> shape >> x >> y;	
		pos[shape - 'A'].push_back({x, y});
	}
	
	for(int i = 0; i < pos[chimney[0] - 'A'].size(); i++){
		pdd elem = pos[chimney[0] - 'A'][i];
		visited[chimney[0] - 'A'][i] = 1;
		backtracking(1, elem, {-DINF, DINF});
		visited[chimney[0] - 'A'][i] = 0;
	}
	
	cout << answer.size() << "\n";
	cout << fixed;
	cout.precision(4);
	for(auto elem : answer){
		if(elem.first == -DINF) cout << "* ";
		else cout << elem.first << " ";
		if(elem.second == DINF) cout << "*\n";
		else cout << elem.second << "\n";
	}
	return 0;
}