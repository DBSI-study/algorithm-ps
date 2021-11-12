#include <iostream>
using namespace std;

bool visited[101];

int main()
{
	int n,x,cnt=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		visited[x]==true ? cnt++ : visited[x]=true;
	}
	cout<<cnt;
}