#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    for(string num : phone_book){
        um[num] = 1;
    }
    
    for(string number : phone_book){
        string prefix = "";
        
        for(int i=0; i<number.size() - 1; i++){
            prefix += number[i];
            if(um.count(prefix)){
                return false;
            }
        }
    }
    
    return true;
}