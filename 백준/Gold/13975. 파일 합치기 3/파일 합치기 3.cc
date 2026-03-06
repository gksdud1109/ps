#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min_cost(){
  int K; cin >> K;
  ll cost=0, lc, rc;
  priority_queue<ll, vector<ll>, greater<>> pq;
  
  while(K--){
    cin >> lc;
    pq.push(lc);
  }
  while(pq.size() != 1){
    lc = pq.top(); pq.pop();
    rc = pq.top(); pq.pop();
    cost += lc + rc;
    pq.push(lc + rc);
  }

  return cost;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;

  while(T--)
    cout << min_cost() << '\n';
}