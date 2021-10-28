#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	long long n;
	long long result=0;
	long long arr[7];
	long long minimum=0;
	cin>>n;
	for(int i=0;i<6;i++)
		cin>>arr[i];
	
	// n=1일때 고려.
	if(n==1){
		sort(arr,arr+6);

		for(int i=0;i<5;i++)
			result+=arr[i];
		cout<<result;
		return 0;
	}
	// 3면 보이는 경우의 주사위
	
	minimum+=min(min(min(arr[1]+arr[2],arr[2]+arr[4]),arr[3]+arr[4]),arr[1]+arr[3]);
	minimum+=min(arr[0],arr[5]);
	result+=4*minimum;
	
	// 2면 보이는 경우의 주사위
	int comp=-5;
	minimum=101;
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			if(i-j==comp || i==j) continue;
			long long tmp=abs(arr[i]+arr[j]);
			if(tmp<minimum)
				minimum=tmp;
				
		}
		comp+=2;
	}
	
	result+=(minimum)*((n-1)*4+(n-2)*4);
	
	
	// 1면 보이는 경우의 주사위
	sort(arr,arr+6);
	result+=arr[0]*((n-2)*(n-1)*4+(n-2)*(n-2));
	
	cout<<result;
	
}