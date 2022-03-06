#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> saveNum(3), option(3);
   	int idx = 0; 
	for(int i = 0; i < dartResult.length(); i++, idx++){
        if(isdigit(dartResult[i + 1])) {
            saveNum[idx] = 10;
            i++;
        }
        else saveNum[idx] = dartResult[i] - '0';
        i++;
		switch(dartResult[i]){
            case 'D':
                saveNum[idx] = pow(saveNum[idx], 2);
                break;
            case 'T':
                saveNum[idx] = pow(saveNum[idx], 3);
        }
        if(i + 1 < dartResult.length() && !isdigit(dartResult[i + 1])) {
            i++;
            option[idx] = (dartResult[i] == '*' ? 1 : -1);
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(option[i] > 0){
            saveNum[i] *= 2;
            if(i > 0) saveNum[i - 1] *= 2;
        }
        else if(option[i] < 0) saveNum[i] *= -1;
    }

    for(int i = 0; i < 3; i++){
        answer += saveNum[i];
    }
    return answer;
}