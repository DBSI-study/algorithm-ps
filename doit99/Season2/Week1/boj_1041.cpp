#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
	long long n,m=0,ans=0;
	long long arr[6]; 
	cin>>n; 
	
	for (int i=0;i<6;i++) {
		cin>>arr[i]; 
		ans+=arr[i];
		m=max(m,arr[i]); 
	} 
	
	if (n==1){
		cout<<ans-m; 
		return 0;
	}

	ans=0; 
	arr[0]=min(arr[0],arr[5]);
	arr[1]=min(arr[1],arr[4]); 
	arr[2]=min(arr[2],arr[3]);

	sort(arr,arr+3); 

	int sum1=arr[0];
	int sum2=sum1+arr[1];
	int sum3=sum2+arr[2];

	ans+=sum3*4; 
	ans+=sum2*(4*(n-2)+4*(n-1));
	ans+=sum1*(4*(n-1)*(n-2)+(n-2)*(n-2));
	cout<<ans;

}
