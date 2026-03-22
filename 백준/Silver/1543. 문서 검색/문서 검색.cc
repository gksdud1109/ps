#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string target, patt;
  getline(cin, target);
  getline(cin, patt);
  int cnt = 0;
  int fi = target.find(patt);
  while(fi != string::npos){
    cnt++;
    fi = target.find(patt, fi+patt.size());
  }
  cout << cnt;
}