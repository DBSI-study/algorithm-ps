#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int leak_amount,tape_length;
	int TapeStartIndex=0;
	int totalTapeCount=1;
	int leak_locations[1001];
	
	cin>>leak_amount>>tape_length;
	
	for(int i=0;i<leak_amount;i++)
		cin>>leak_locations[i];
	
	sort(leak_locations,leak_locations+leak_amount);
	
	for(int i=1;i<leak_amount;i++){
		if(leak_locations[i]-leak_locations[TapeStartIndex]>tape_length-1){
			TapeStartIndex=i;
			totalTapeCount++;
		}

	}
	
	cout<<totalTapeCount;
}