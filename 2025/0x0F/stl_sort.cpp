#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
  if(a%5 != b%5) return a%5 < b%5;
  return a < b;
}

int main(void){
  int c[7] = {1,2,3,4,5,6,7};
  sort(c, c+7, cmp);
}