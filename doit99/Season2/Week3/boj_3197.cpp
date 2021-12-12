#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
char map[1500][1500];
bool visited[1500][1500];
bool isMelt[1500][1500];
vector<pair<int,int>> swan;
int r,c;
int cnt;
int start_swan_y;
int start_swan_x;
int end_swan_y;
int end_swan_x;

bool flag=false;
void dfs(int y, int x){
	visited[y][x]=true;
	if(flag) return;
	if(y==end_swan_y && x==end_swan_x){
		flag=true;
		return;
	}
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny>=0 && ny<r && nx>=0 && nx<c){
			if(map[ny][nx]!='X' && !visited[ny][nx]){
				dfs(ny,nx);
				visited[ny][nx]=false;
			}
		}
	}
	return;
}

//두 백조 만나는지 체크하기
bool swan_meet(){
	start_swan_y=swan[0].second;
	start_swan_x=swan[0].first;
	end_swan_y=swan[1].second;
	end_swan_x=swan[1].first;
	
	dfs(start_swan_y,start_swan_x);
	
		if(flag) return true;
	return false;
	
}
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char tmp;
			cin>>tmp;
			map[i][j]=tmp;
			if(tmp=='L')
				swan.push_back({j,i});
		}
	}
	
	while(!flag){
		swan_meet();
		//빙하 녹일지 체크하기
		memset(isMelt,false,sizeof(isMelt));
		memset(visited,false,sizeof(visited));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				for(int x=0;x<4;x++){
					int ny=i+dy[x];
					int nx=j+dx[x];
					if(ny>=0 && ny<r && nx>=0 && nx<c){
						if(map[i][j]=='X' && map[i+dy[x]][j+dx[x]]=='.'){
							isMelt[i][j]=true;
						}
					}
				}
			}
		}
		// 빙하 녹이기
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(isMelt[i][j])
					map[i][j]='.';
			}
		}
		cnt++;
	}
	cout<<cnt-1;
}
