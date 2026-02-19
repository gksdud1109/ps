#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll D[105];
int T;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  D[1] = 1; D[2] = 1; D[3] = 1;

  for(int i=4; i<=100; i++){
    D[i] = D[i-2] + D[i-3];
  }

  while(T--){
    int n;
    cin >> n;
    cout << D[n] << '\n';
  }
}