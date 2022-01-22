#include <iostream>
#include <cstring>
using namespace std;

int s=10000000;
bool check[20000003];
int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n,m,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		check[x+s]=true;
	}
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>x;
		cout<<((check[x+s]==true) ? "1" : "0")<<" ";
	}
}