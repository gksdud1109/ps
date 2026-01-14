#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C, result;
  string s_result;
  int countNum[10] = {0};

  cin >> A >> B >> C;
  result = A * B * C;

  s_result = std::to_string(result);

  for (char ch : s_result)
  {
    countNum[ch - '0']++;
  }
  for (int i = 0; i < 10; i++)
  {
    cout << countNum[i] << "\n";
  }
}