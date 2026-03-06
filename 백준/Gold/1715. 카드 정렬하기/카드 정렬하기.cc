#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
  int N; cin >> N;
  while(N--){
    int x; cin >> x;
    pq.push(x);
  }

  int ans = 0;
  while(pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a+b;
    pq.push(a+b);
  }
  cout << ans;
}
// 누적비용을 최소화하는 그리디 접근, 허프만 코딩과 같은 원리