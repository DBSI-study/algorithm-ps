#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MLTPLY 65536

using namespace std;

string lowerString(string str){
    for(int i = 0; i < str.length(); i++){
       	str[i] = (tolower(str[i]));
    }
    return str;
}

void printVec(vector<string> vec){
    for(auto elem : vec){
        cout << elem << " ";
    }
    cout << "\n";
}

vector<string> makeCluster(string str){
    vector<string> ret;
   	for(int i = 0; i < str.length() - 1; i++){
        if(!isalpha(str[i]) || !isalpha(str[i + 1])) continue;
        string temp = "";
        (temp += str[i]) += str[i + 1];
    	ret.push_back(temp);
    } 
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    str1 = lowerString(str1);
    str2 = lowerString(str2);
    
    vector<string> vec1 = makeCluster(str1), vec2 = makeCluster(str2);
    sort(vec1.begin(), vec1.end()), sort(vec2.begin(), vec2.end());
   	// 두 집합 모두 공집합일 경우 
    if(vec1.size() == 0 && vec2.size() == 0) return MLTPLY;
    
    vector<string> unionVec;
   	int left = 0, right = 0; 
    double interCnt = 0;
    while(left < vec1.size() && right < vec2.size()){
       	if(vec1[left] < vec2[right]) {
           	unionVec.push_back(vec1[left++]);
        }
        else if(vec1[left] > vec2[right]){
           	unionVec.push_back(vec2[right++]);
        }
        else{
           	unionVec.push_back(vec2[right]);
           	interCnt++; 
            left++; right++;
        }
    }
    while(left < vec1.size()){
       	unionVec.push_back(vec1[left++]);
    }
    while(right < vec2.size()){
       	unionVec.push_back(vec2[right++]);
    }
    
    answer = interCnt / unionVec.size() * (double)MLTPLY;
    return answer;
}