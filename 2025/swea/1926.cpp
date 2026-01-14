#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    string s = to_string(i);
    int clap = 0;
    for (char c : s) {
      if (c == '3' || c == '6' || c == '9') clap++;
    }
    if (clap > 0) {
      for (int j = 0; j < clap; j++) cout << '-';
      cout << ' ';
    } else {
      cout << i << ' ';
    }
  }
  return 0;
}