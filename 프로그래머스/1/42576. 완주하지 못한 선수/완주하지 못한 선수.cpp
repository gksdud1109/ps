#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    for(auto p : participant)
        um[p]++;
    
    for(auto c : completion)
        um[c]--;
    
    for(auto com : um){
        if(com.second > 0){
            answer = com.first;
            break;
        }
    }
    
    return answer;
}