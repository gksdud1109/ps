#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<tuple<int, int, string>> members;
  for(int i=0; i<N; i++){
    int age;
    string name;
    cin >> age >> name;
    members.push_back({age, i, name}); // 순서정보 i로 sort()에서도 순서 보장
  }
  sort(members.begin(), members.end());
  for(auto [age, _, name] : members)
    cout << age << " " << name << '\n';
}