#include <bits/stdc++.h>
using namespace std;

int alpha[26]; // 전역 선언시 알아서 0으로 채워짐

int main(void){
  // int alpha[26]; 쓰레기 값이 채워짐

  string input;
  cin >> input;

  for(auto c : input)
    alpha[c-'a']++;

  for(int i=0; i<26; i++)
    cout << alpha[i] << ' ';
}