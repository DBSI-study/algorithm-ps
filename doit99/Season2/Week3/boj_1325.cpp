#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
vector<int> v[10001];
bool visited[10001];
int how_many_pc[10001];
int cnt;

void dfs(int node){
    if(visited[node])
		return;
	
    visited[node] = true;
    cnt++;
    for(int i=0; i<v[node].size(); i++)
        dfs(v[node][i]);
}
 
int main() {
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
		int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    
	int max_pc=0;
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        cnt=0;
        dfs(i);
        how_many_pc[i]=cnt;
		if(max_pc<how_many_pc[i])
            max_pc=how_many_pc[i];
    }
    
    for(int i=0; i<=n; i++)
        if(how_many_pc[i]==max_pc)
            cout<<i<<' ';
}
