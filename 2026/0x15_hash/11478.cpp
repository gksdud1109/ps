#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  unordered_set<string> us;
  string s; cin >> s;
  for(int i=0; i<s.length(); i++){
    string tmp = "";
    for(int j=i; j<s.length(); j++){
      tmp += s[j];
      us.insert(tmp);
    }
  }

  cout << us.size();
}