#include <iostream>
#include <string>
using namespace std;

int digit(int x){
	int res=0;
	while(x>0){
		res+=x%10;
		x-=x%10;
		x/=10;
	}
	return res;
	
}

int main()
{
	int num;
	string s;
	cin>>s;
	
	for(int i=0;i<stoi(s);i++){
		if(i+digit(i)==stoi(s)){
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
}