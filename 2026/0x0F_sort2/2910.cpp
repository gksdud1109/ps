#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, C;
vector<pair<int, int>> arr; // {cnt, num}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
  return a.X > b.X;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    bool chk = false;
    for(auto &a : arr){
      if(a.Y == x){
        chk = true;
        a.X++;
        break;
      }
    }
    if(!chk) arr.push_back({1, x});
  }

  stable_sort(arr.begin(), arr.end(), cmp); // 입력 순서 보장
  for(auto b : arr)
    while(b.X--) cout << b.Y << ' ';
}