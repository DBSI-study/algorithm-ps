
#include <iostream>
using namespace std;

int main()
{
	int h,w,x,y;
	int arr[601][601];
	int brr[601][601];
	
	scanf("%d %d %d %d",&h,&w,&x,&y);
	for(int i=0;i<h+x;i++)
		for(int j=0;j<w+y;j++)
			scanf("%d",&brr[i][j]);


	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
		{
			if(i>=x && j>=y) break;
			arr[i][j]=brr[i][j];
		}
	}

	for(int i=x;i<h;i++)
		for(int j=y;j<w;j++)
			arr[i][j]=brr[i][j]-arr[i-x][j-y];
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	
}