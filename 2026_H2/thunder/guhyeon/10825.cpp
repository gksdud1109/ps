#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<tuple<int, int, int, string>> stu;

  while(n--){
    string name;
    int kor, eng, math;

    cin >> name >> kor >> eng >> math;
    stu.push_back({-kor, eng, -math, name});
  }

  sort(stu.begin(), stu.end());
  for(auto& s: stu)
    cout << get<3>(s) << '\n';
}