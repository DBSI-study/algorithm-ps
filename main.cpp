#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define pss pair<string, string>

using namespace std;

void change_userid_to_nickname(vector<pss>& save, vector<pss>& nick_name_record){
	// 해당하는 user_id 에 대해서 가장 마지막 닉네임으로만 변환해주면 된다.
	sort(nick_name_record.begin(), nick_name_record.end());
	
	map<string, string> mp;
	for(int i = 0; i < nick_name_record.size() - 1; i++){
		if(nick_name_record[i].first != nick_name_record[i + 1].first){
			mp[nick_name_record[i].first] = nick_name_record[i].second;
		}
	}	
	mp[nick_name_record.back().first] = nick_name_record.back().second;
	
	for(auto &elem : save){
		elem.first = mp[elem.first];
	}
}

vector<string> solution(vector<string> record) {
	vector<pair<string, string>> save, nick_name_record;
	vector<string> answer;
	
	for(string & input : record){
		string cmd = input.substr(0, input.find(' '));
		input = input.substr(input.find(' ') + 1, input.size());
		string user_id = input.substr(0, input.find(' '));
		input = input.substr(input.find(' ') + 1, input.size());
		string nick_name = input;
		if(cmd == "Leave"){
			save.push_back({user_id, "님이 나갔습니다."});
			continue;
		}	
		nick_name_record.push_back({user_id, nick_name});
		if(cmd == "Enter")	{
			save.push_back({user_id, "님이 들어왔습니다."});
		}
		
	
	}
	change_userid_to_nickname(save, nick_name_record);
	for(auto elem : save){
		answer.push_back(elem.first + elem.second);
	}
    return answer;
}

int main(void){
	string input;
	getline(cin, input);
	vector<string> record;
	
	input = input.substr(2, input.size());
	while(1){
		record.push_back(input.substr(0, input.find("\"")));
		cout << input << "\n";
		input = input.substr(input.find("\""), input.size());
		if(input.size() == 2) break;
		input = input.substr(input.find("\"", 1) + 1, input.size());
	}
	
	vector<string> answer = solution(record);
	for(auto elem : answer){
		cout << elem << "\n";
	}
	return 0;
}