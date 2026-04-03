#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    
    unordered_map<int, int> um;
    for(auto n : nums)
        um[n]++;
    
    if(um.size() >= N/2)
        answer = N/2;
    else
        answer = um.size();
    
    return answer;
}