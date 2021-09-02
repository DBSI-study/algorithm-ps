#include <iostream>
#include <vector>
using namespace std;

vector<int> v[500001];
bool visited[500001];
int cnt=0;
void DFS(int x, int h)
{
	visited[x]=true;
	if(v[x].size()==1 && x!=1){
		cnt+=h;
		return;
	}
	for(int i=0;i<v[x].size();i++){
		if(!visited[v[x][i]]){
			DFS(v[x][i],h+1);
			visited[v[x][i]]=false;
		}
	}
}

int main()
{
	int n,a,b;
	scanf("%d",&n);
	
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);	
		v[b].push_back(a);
	}
	visited[1]=true;
	DFS(1,0);
	printf(cnt%2==1 ? "Yes" : "No");
//	cnt%2==1 ? printf("Yes") : printf("No");
}