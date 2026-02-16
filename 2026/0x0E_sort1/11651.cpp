#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[100004];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  for(int i=0; i<N; i++)
    cin >> p[i].second >> p[i].first;

  sort(p, p+N);
  for(int i=0; i<N; i++)
    cout << p[i].second << ' ' << p[i].first << '\n';
}
// second에 x를 저장해서 sort(pair)정렬시에 
// first에 들어간 y우선기준으로 정렬
// 무조건 first우선으로 정렬하는 sort 함수 정의 이용