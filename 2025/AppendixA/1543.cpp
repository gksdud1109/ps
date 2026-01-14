#include <bits/stdc++.h>
using namespace std;

int main(void){
  string s, search_s;
  getline(cin, s);
  getline(cin, search_s);

  int count=0;
  int f=s.find(search_s);
  while(f != string::npos){
    count++;
    f = s.find(search_s, f+search_s.size());
  }
  cout << count;
}