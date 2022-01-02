#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string str[10];
	int alpha[26]={0,};
	int num=9;
	int result=0;
	
	for(int i=0;i<n;i++)
		cin>>str[i];
	
	for(int i=0;i<n;i++)
	{
		int pow=1; 
		for(int j=str[i].size()-1;j>=0;j--)
		{
			int alphabet=str[i][j]-'A';
			alpha[alphabet]+=pow;
			pow*=10;
		}
	}
	
	sort(alpha,alpha+26);
	for(int i=25;i>=0;i--){
		if(alpha[i]==0) break;
		result+=(alpha[i]*num);
		num--;
	}
	cout<<result;
}
	