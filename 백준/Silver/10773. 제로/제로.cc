#include <bits/stdc++.h>
using namespace std;

int S[100001];
int pos, answer=0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K;
  cin >> K;

  while(K--){
    int num;
    cin >> num;

    if(num == 0) pos--;
    else {
      S[pos] = num;
      pos++;
    }
  }

  for(int i=0; i<pos; i++)
    answer += S[i];

  cout << answer;
}