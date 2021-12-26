#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
  
int k,v,e;
vector<int> graph[20001];
int value[20001];
 
void DFS(int node,int color)
{
	value[node] = color;

	for (int i=0;i<graph[node].size();i++)
	{
		 int next=graph[node][i];
		 if (!value[next])
				 DFS(next,3-color);
	}
}
 
bool bipartite(void)
{
	for (int i=1;i<=v;i++)
		 for (int j=0;j<graph[i].size();j++)
		 {
			 int next=graph[i][j];
			 if (value[i]==value[next])
				 return false;
		 }
	return true;
}
 
int main(void)
{
	int a,b;
	scanf("%d",&k);

	for (int i=0;i<k;i++)
	{
		for (int j=1;j<20001;j++)
			graph[j].clear();
		memset(value,0,sizeof(value));
		scanf("%d %d",&v,&e);
		for (int j=0;j<e;j++)
		{
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int j=1;j<=v;j++)
			if (value[j]==0)
				DFS(j,1);

		if (bipartite())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}