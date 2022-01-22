#include <iostream> 
#include <algorithm> 
using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); 
	cout.tie();
	
	int x,n;
	int arr[1000001];
	
	while (cin>>x) {
		x *= 10000000;
		cin>>n; 
		for(int i=0;i<n;i++) 
			cin>>arr[i]; 
		sort(arr, arr+n);
		
		int l=0,r=n-1,sum=0;
		bool flag=false;
		while (l<r){ 
			sum=arr[l]+arr[r];
			if(sum==x){
				flag=true;
				break;
			}
			else if(sum<x) l++;
			else r--;
		} 
		
		if (flag)
			cout<<"yes "<<arr[l]<<" "<<arr[r]<<'\n'; 
		else cout<<"danger\n"; 
	}
	return 0;
}
