#include <string>
#include <iostream>
#include <vector>

using namespace std;

string printDecryptedMap(int num, int n){
    string ret;
    vector<bool> temp;
   	while(num > 0) {
        temp.push_back(num % 2);
        num /= 2;
    }
    while(temp.size() < n) temp.push_back(0);
    
    for(int i = temp.size() - 1; i >= 0; i--){
        if(temp[i]) ret.push_back('#');
        else ret.push_back(' ');
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
   	
    vector<int> combined;
    for(int i = 0; i < n; i++){
        answer.push_back(printDecryptedMap(arr1[i] | arr2[i], n));
    }
    
    return answer;
}