#include <bits/stdc++.h>
#define Max 201

using namespace std;

int root[Max];

int find(int x){
	if(x == root[x]) return x;
	return root[x] = find(root[x]);
}

void unify(int x, int y){
	x = find(x);
	y = find(y);
	if(x < y){
		root[x] = y;
	}	
	else root[y] = x;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	int input;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		root[i] = i;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> input;	
			if(input) unify(i, j);
		}
	}	
	
	int control, travel_route;
	cin >> control;
	for(int i = 1; i < M; i++){
		cin >> travel_route;
		if(find(control - 1) != find(travel_route - 1)) {cout << "NO\n"; return 0;}
	}
	cout << "YES\n";
	return 0;
	
	return 0;
}