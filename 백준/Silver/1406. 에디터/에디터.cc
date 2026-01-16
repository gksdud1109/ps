#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string preset;
  int M;
  cin >> preset >> M;

  list<char> L;
  for(auto c : preset)
    L.push_back(c);
  auto cursor = L.end();

  while(M--) {
    char comm;
    cin >> comm;

    if(comm == 'P'){
      char addChar;
      cin >> addChar;
      L.insert(cursor, addChar);
    }
    else if(comm == 'L'){
      if(cursor != L.begin()) cursor--;
    }
    else if(comm == 'D'){
      if(cursor != L.end()) cursor++;
    }
    else {
      if(cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for(auto c : L)
    cout << c;
}