#include <bits/stdc++.h>
using namespace std;

string input;
vector<string> v;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  for(int i=0; i<input.length(); i++){
    string tmp = input.substr(i);
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  for(auto ss : v) cout << ss << '\n';
}