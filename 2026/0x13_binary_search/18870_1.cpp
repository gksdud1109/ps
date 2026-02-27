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
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  // unique()가 중복제거 후 쓰레기값이 시작하는 지점을 반환한다.

  for(int i=0; i<N; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}