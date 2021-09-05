// 나무 재테크
// vector를 사용한 풀이
#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 11

using namespace std;

int N, M, K;
int field[Max][Max], A[Max][Max];
int tempfield[Max][Max];
vector<int> tree[Max][Max];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void printTreeSize(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << tree[i][j].size() << " ";
		}
		cout << "\n";
	}
	
}
void printField(){
    cout << "field : \n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int countLivingTreeAfter(int time){
	
	while(time--){
        // printTreeSize();
        // printField();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int k = tree[i][j].size() - 1; k >= 0; k--){
					int now = tree[i][j][k];
					if(field[i][j] - now < 0){
						tempfield[i][j] += now / 2;	
						tree[i][j].erase(k + tree[i][j].begin());
					}
					else{
						field[i][j] -= now;
						tree[i][j][k]++;
					}
				}
				field[i][j] += tempfield[i][j];
				tempfield[i][j] = 0;
			}
		}	
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(auto now: tree[i][j]){
					if(now % 5) continue;
					for(int k = 0; k < 8; k++){
						int ny = i + dy[k], nx = j + dx[k];
						if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
						tree[ny][nx].push_back(1);
					}
				}	
			}
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				field[i][j] += A[i][j];
			}
		}
	}
	int ret = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ret += tree[i][j].size();	
		}
	}
	return ret;	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
			field[i][j] = 5;
		}
	}
	int x, y, z;
	priority_queue<pair<pii, int>> pq;
	for(int i = 0; i < M; i++){
		cin >> x >> y >> z;
		pq.push({{x - 1, y - 1}, -z});
	}
	while(!pq.empty()){
		pii now = pq.top().first;
		int age = -pq.top().second;
        pq.pop();
		tree[now.first][now.second].push_back(age);
	}

	cout << countLivingTreeAfter(K) << "\n";
	return 0;
}