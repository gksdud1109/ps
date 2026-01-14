#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int N;
  cin >> N;

  int countGW = 0;

  while (N--)
  {
    stack<char> GW;
    string s;
    char temp;
    cin >> s;

    for (auto a : s)
    {
      if (!GW.empty() && GW.top() == a)
        GW.pop();
      else
        GW.push(a);
    }
    if (GW.size() == 0)
      countGW++;
  }
  cout << countGW << "\n";
}