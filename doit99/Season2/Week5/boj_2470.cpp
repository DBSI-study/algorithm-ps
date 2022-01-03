#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,left=0,right;
	int arr[100001];
	int min_gap=2147000000;
	pair<int,int> answer;
	cin>>n;
	right=n-1;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
		
	while(left<right){
		int gap=arr[left]+arr[right];
		
		if(abs(gap)<min_gap){
			min_gap=abs(gap);
			answer=make_pair(arr[left],arr[right]);
			if(gap==0) break;
		}
		
		if(gap>0) right--;
		else left++;
	}
	cout<<answer.first<<" "<<answer.second;
}