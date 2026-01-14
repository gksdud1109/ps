#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  while (N--)
  {
    string a, b;
    int arr[26] = {};
    bool strfry = true;
    cin >> a >> b;

    for (auto c : a)
      arr[c - 'a']++;
    for (auto c : b)
      arr[c - 'a']--;

    for (int i = 0; i < 26; i++)
      if (arr[i] != 0)
        strfry = false;
    if (strfry)
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }
}