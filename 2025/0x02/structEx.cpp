#include <bits/stdc++.h>
using namespace std;

struct pt
{
  int x, y;
};
void func(pt a)
{
  a.x = 10;
}
int main(void)
{
  pt tmp = {0, 0};
  func(tmp);
  cout << tmp.x;
}