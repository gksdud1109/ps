#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> flower;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N; cin >> N;

  for(int i=0; i<N; i++){
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    flower.push_back({sm*100+sd, em*100+ed});
  }

  int t = 301;
  int ans = 0;
  while(t<1201){
    int nxt_t = t; // 이번에 추가할 꽃으로 인해 변경된 시간
    for(int i=0; i<N; i++){
      if(flower[i].X <= t && flower[i].Y > nxt_t)
        nxt_t = flower[i].Y;
    }
    if(nxt_t == t){
      cout << 0;
      return 0;
    }
    ans++;
    t = nxt_t;
  }
  cout << ans;
}