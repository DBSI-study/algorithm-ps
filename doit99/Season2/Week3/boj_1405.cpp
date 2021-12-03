#include<iostream>
using namespace std;

int n;
bool visited[100][100];
double direc_percent[4];
double ans;

int y_arr[4] = {0,0,-1,1};
int x_arr[4] = {1,-1,0,0};

void dfs(int y, int x, double per, int cnt) {
    if (cnt == n) {
        ans += per;
        return;
    }
 
    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + y_arr[i];
        nx = x + x_arr[i];
        if (visited[ny][nx] == 0) { //재방문을 안 했을 경우만 탐색하며 확률 더함.
            visited[ny][nx] = 1;
            dfs(ny, nx, per * direc_percent[i], cnt + 1);
            visited[ny][nx] = 0;
        }
    }
}
 
 
int main(){
    cin >> n;
    for (int i = 0; i < 4; i++) {
		double tmp;
		cin>>tmp;
		direc_percent[i]=tmp/100;
    }
 
 
    visited[14][14] = 1;
    dfs(14,14,1,0);
 
    //cout.precision(11);
    //cout.fixed;
    cout << ans;
}

