#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  vector<tuple<int, int, int, string>> stu;
  while(N--){
    string name;
    int kor, eng, math;

    cin >> name >> kor >> eng >> math;
    stu.push_back({-kor, eng, -math, name});
  }
  sort(stu.begin(), stu.end());
  for(auto& s : stu)
    cout << get<3>(s) << '\n';
}
// pair와 tuple은 비교 연산자가 이미 정의되어있어 앞에서부터 차례대로 비교함
// cmp() 별도 정의 없이 sort()호출만으로 정렬가능
// sort()는 기본 오름차순(작 -> 큰)이므로 내림차순에는 입력부터 -를 붙이는 테크닉