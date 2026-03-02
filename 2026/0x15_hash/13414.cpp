#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K, L; cin >> K >> L;
  unordered_map<string, int> signup{};
  for(int i=0; i<L; i++){
    string student_num;
    cin >> student_num;
    signup[student_num] = i;
  }
  vector<pair<string,int>> slist(signup.begin(), signup.end());
  sort(slist.begin(), slist.end(), [](auto& a, auto& b){return a.Y < b.Y;});
  int en = min(K, (int)slist.size());

  for(int i=0; i<en; i++)
    cout << slist[i].X << '\n';
}