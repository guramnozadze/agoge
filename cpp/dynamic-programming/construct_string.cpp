//
// Created by gukan on 12/2/2024.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<vector<string>> all_construct(string target, vector<string> &chunks, unordered_map<string, bool> &memo) {
	if(target.empty()) {
		return {{}};
	}

	vector<string> result ={};
	for(int i = 0; i < chunks.size(); i++){
		string chunk = chunks[i];
		if(chunk == target.substr(0, chunk.length())){
			string suffix = target.substr(chunk.length());
			vector<vector<string>> suffixWays = all_construct(suffix, chunks,memo);
			vector<string> targetWays = {};
			for (int i = 0; i < suffixWays.size(); i++) {
				for (int j = 0; j < suffixWays[i].size(); j++) {
					targetWays.push_back({chunk});
					targetWays.push_back(suffixWays[i][j]);
				}
			}
			result = targetWays;
		}
	}

	return result;
}


int count_construct(string target, vector<string> &chunks, unordered_map<string, bool> &memo) {
	if (memo.count(target)) {
		return memo[target];
	}
	if(target.empty()) {
		return 1;
	}

	int totalCount = 0;

	for(int i = 0; i < chunks.size(); i++){
		string chunk = chunks[i];
		if(chunk == target.substr(0, chunk.length())){
			int numWaysForRest = count_construct(target.substr(chunk.length()), chunks, memo);
			totalCount = totalCount + numWaysForRest;
		}
	}

	return totalCount;
}


bool can_construct(string target, vector<string> &chunks, unordered_map<string, bool> &memo) {
	if (memo.count(target)) {
		return memo[target];
	}
	if(target.empty()) {
    	return true;
    }

    for(int i = 0; i < chunks.size(); i++){
    	string chunk = chunks[i];
    	if(chunk == target.substr(0, chunk.length())){
			if (can_construct(target.substr(chunk.length()), chunks, memo) == true) {
				memo[target] = true;
				return true;
			}
    	}
    }

	memo[target] = false;
    return false;
}

int main() {

	vector<string> chunks = {"e","f"};
	unordered_map<string, bool> memo = {};
	cout << count_construct("eeef", chunks, memo) << endl;
	return 0;
}
