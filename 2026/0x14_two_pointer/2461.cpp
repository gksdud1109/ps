#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, cnt, en, ans = 0x7f7f7f7f;
int chk[1005];
vector<pair<int,int>> ability;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int num;
      cin >> num;
      ability.push_back({num, i});
    }
  }

  sort(ability.begin(), ability.end());

  for(int st=0; st<n*m; st++){
    while(cnt<n && en < n*m) {
      if(chk[ability[en].Y] == 0) cnt++;
      chk[ability[en].Y]++;
      en++;
    }

    if(cnt != n) break;
    ans = min(ans, ability[en-1].X - ability[st].X);
    chk[ability[st].Y]--;
    if(chk[ability[st].Y] == 0) cnt--;
  }

  cout << ans;
  return 0;
}