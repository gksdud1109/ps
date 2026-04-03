#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    for(vector<string> c : clothes){
        um[c[1]]++;
    }
    
    for(auto item : um){
        answer *= (item.second + 1);
    }
    
    return answer - 1;
}