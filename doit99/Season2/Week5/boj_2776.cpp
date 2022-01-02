#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int fact[1000001];
int check[1000001];

bool binary_search(int x, int left, int right){
	int mid=(left+right)/2;
	if(left<=right){
		if(x==fact[mid]) return true;
		else if(x<fact[mid]) return binary_search(x,left,mid-1);
		else return binary_search(x,mid+1,right);
	}
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int t,n,m;
	cin>>t;
	for(int i=0;i<t;i++){
		memset(fact,0,sizeof(fact));
		memset(check,0,sizeof(check));
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>fact[j];
		sort(fact,fact+n);
		cin>>m;
		for(int j=0;j<m;j++)
			cin>>check[j];
		for(int j=0;j<m;j++)
			cout<<binary_search(check[j],0,m-1)<<'\n';
	}
}