#include <iostream>
using namespace std;

int main(){
	int n,ans;
	int arr[100001];
	int dp[100001];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	dp[0]=arr[0];
	ans=arr[0];
	
	for(int i=1;i<n;i++){
		//dp[i]=arr[i];
		if(arr[i-1]>0)
			arr[i]+=arr[i-1];
		ans=max(ans,arr[i]);
	}
	cout<<ans;
}