#include <iostream>
using namespace std;

int a[1000001];
int b[1000001];
int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n,m;
	int a_pointer=0,b_pointer=0;
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<m;j++)
		cin>>b[j];
	
	a[n]=b[m]=2147000000;
	for(int i=0;i<n+m;i++)
		cout<< (a[a_pointer]<b[b_pointer] ? a[a_pointer++] : b[b_pointer++])<<" ";
}