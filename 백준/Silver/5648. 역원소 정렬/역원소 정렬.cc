#include <bits/stdc++.h>
using namespace std;

int n;
string cur;
vector<long long> input;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> cur;
    reverse(cur.begin(), cur.end());
    input.push_back(stoll(cur));
  }
  sort(input.begin(), input.end());

  for(auto i: input) 
    cout << i << '\n';
}