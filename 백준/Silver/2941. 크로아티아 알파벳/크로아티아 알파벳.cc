#include <bits/stdc++.h>
using namespace std;

vector<string> cro_list = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;

  for(auto cro : cro_list){
    while(true){
      int pos = input.find(cro);
      if(pos == string::npos) break;
      input.replace(pos, cro.size(), "1");
    }
  }

  cout << input.size();
}