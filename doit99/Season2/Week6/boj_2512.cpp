#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n,m,ans=0;
	int arr[100001];
	int summ=0;
	long long tmp=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		summ+=arr[i];
	}
	cin>>m;
	sort(arr,arr+n);
	
	if(summ<=m){
		cout<<arr[n-1];
		return 0;
	}
	
	for(int i=0;i<n;i++){
		long long test;
		test=(m-tmp)/(n-i);
		if(test>ans) ans=test;
		tmp+=arr[i];
	}
	cout<<ans;	
}