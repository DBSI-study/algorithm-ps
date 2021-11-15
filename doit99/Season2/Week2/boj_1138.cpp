#include <iostream>
using namespace std;
 
int n;
int arr[11];
 
int main(){
	cin>>n;

	for(int i=1;i<=n;i++){
		int leftCount;
		cin>>leftCount;

		for(int j=1;j<=n;j++){
			if(arr[j]==0){
				if(leftCount==0){
					arr[j]=i;
					break;
				}
				leftCount--;
			}
		}
	}

	for (int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
}
