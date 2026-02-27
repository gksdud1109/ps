#include <bits/stdc++.h>
using namespace std;

int N;
int x[1000005];
vector<int> tmp, uni;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> x[i];
    tmp.push_back(x[i]);
  }
  sort(tmp.begin(), tmp.end());
  for(int i=0; i<N; i++){
    if(i==0 || tmp[i-1] != tmp[i])
      uni.push_back(tmp[i]);
  }

  for(int i=0; i<N; i++){
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
  }
}