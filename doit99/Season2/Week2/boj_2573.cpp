#include <iostream>
#include <cstring>
using namespace std;

int map[301][301];
int meltAmount[301][301];
bool check[301][301];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int n,m,cnt=0;

bool AllZero(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]>0) return false;
	return true;
}

void dfs(int y, int x){
	check[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(map[ny][nx]>0 && !check[ny][nx])
			dfs(ny,nx);	
	}
}

bool isSeparated(){
	bool flag=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]>0){
				dfs(i,j);
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]>0 && !check[i][j])
				return true;
	return false;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
	
	while(!AllZero()){
		if(isSeparated()) break;
		memset(meltAmount,0,sizeof(meltAmount));
		memset(check,false,sizeof(check));
		
		for(int i=1;i<n-1;i++){
			for(int j=1;j<m-1;j++){
				for(int k=0;k<4;k++){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(map[ny][nx]<=0)
						meltAmount[i][j]++;
				}
			}
		}
		
		for(int i=1;i<n-1;i++)
			for(int j=1;j<m-1;j++)
				map[i][j]-=meltAmount[i][j];
		cnt++;

	}
	
	if(AllZero())
		cnt=0;
	
	cout<<cnt;
	
}