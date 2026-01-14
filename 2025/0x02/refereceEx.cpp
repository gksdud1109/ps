#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int x = 10;
  int &y = x;
  int *z = &x;

  cout << "x: " << x << ",y: " << y << ",z: " << *z << endl;
  y++;
  cout << "x: " << x << ",y: " << y << ",z: " << *z << endl;

  cout << "x의 주소값: " << &x << ",y: " << &y << ",z: " << z << endl;
}
