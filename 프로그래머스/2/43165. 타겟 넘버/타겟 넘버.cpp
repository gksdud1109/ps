#include <bits/stdc++.h>
using namespace std;

int plusminus(vector<int> numbers, int idx, int sum, int target){
    if(idx >= numbers.size())
        return (sum == target) ? 1 : 0;
    int plus = plusminus(numbers, idx+1, sum+numbers[idx], target);
    int minus = plusminus(numbers, idx+1, sum-numbers[idx], target);
    return plus+minus;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    return plusminus(numbers, 0, 0, target);
}