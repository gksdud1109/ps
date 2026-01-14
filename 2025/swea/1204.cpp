#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int testnum, ans, maxNum=0, mostfreqNum=0;
    int num[105]={0};

    cin >> testnum;
    for(int i=0; i<1000; i++){
      int score=0;
      cin >> score;
      num[score]++;
    }

    for(int i=1; i<101; i++){
      if(mostfreqNum <= num[i]){
        mostfreqNum = num[i];
        maxNum = i;
      }
    }
    cout << '#' << testnum << ' ' << maxNum << '\n';
  }
  return 0;
}