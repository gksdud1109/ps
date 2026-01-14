#include <bits/stdc++.h>
using namespace std;

int D[12];
int test_case;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> test_case;

  D[1]=1;
  D[2]=2;
  D[3]=4;
  for(int i=4; i<12; i++)
    D[i] = D[i-1]+D[i-2]+D[i-3];

  for(int i=0; i<test_case; i++){
    int n;
    cin >> n;
    cout << D[n] << '\n';
  }
}