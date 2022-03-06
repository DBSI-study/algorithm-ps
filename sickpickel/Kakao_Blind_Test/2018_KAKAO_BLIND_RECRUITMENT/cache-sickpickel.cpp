#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

void printCache(map<int, string>& cache){
    for(auto it = cache.begin(); it != cache.end(); it++){
        cout << "(" << it->first << ", " << it->second << ") / ";
    }
    cout << "\n";
}
    
void printSavedAge(map<string, int> & saveAge){
     for(auto it = saveAge.begin(); it != saveAge.end(); it++){
        cout << "(" << it->first << ", " << it->second << ") / ";
    }
    cout << "\n";   
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    
    int answer = 0, idx = 0;
    map<int, string> cache;
    map<string, int> saveAge;
    
    for(string city : cities){
        // 소문자 통일
        for(int k = 0; k < city.length(); k++){
           	city[k] = tolower(city[k]);
        }
        // 도시의 가장 최근 방문 시간을 저장
        if(saveAge.find(city) == saveAge.end()){
            saveAge.insert({city, idx});
        }
        // 가장 최근 방문 시간으로 캐쉬 내부에 도시가 저장됐는지 확인 
        auto it = saveAge.find(city);
        if(cache.find(it->second) != cache.end()){
            cache.erase(cache.find(it->second));
           	answer += 1; 
        }
        else {
            if(cache.size() == cacheSize) cache.erase(cache.begin());
            answer += 5;
        }
        // 캐쉬와 도시 최근 방문시간 DB에 현재 방문한 데이터를 넣어준다.
        cache.insert({idx, city});
        saveAge.erase(it);
        saveAge.insert({city, idx});
        idx++;
    }
   	
    return answer;
}