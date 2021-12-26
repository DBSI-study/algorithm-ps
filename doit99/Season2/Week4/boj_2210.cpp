#include <iostream>
#include <set>
using namespace std;
 
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int map[5][5];
set<int> s;
 
void dfs(int y,int x,int num,int cnt){
    if(cnt==5){
        s.insert(num);
        return;
    }
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if(ny>=0 && ny<5 && nx>=0 && nx<5)
    		dfs(ny,nx,num*10+map[ny][nx],cnt+1);
    }
}

int main(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>map[i][j];
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            dfs(i,j,map[i][j],0);
    
    cout<<s.size();
}
