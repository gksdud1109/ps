#include <bits/stdc++.h>
using namespace std;

int L, C;
char input[20];
int arr[20];
bool isused[20];

bool aeiou(char t){
  return t == 'a' || t=='e' || t=='i' || t=='o' || t=='u';
}

void func(int k, int st){
  if(k == L){
    bool flag = false;
    int jaum = 0;
    int moum = 0;
    for(int i=0; i<L; i++){
      if(aeiou(input[arr[i]])) moum++;
      else jaum++;
    }
    if(moum >= 1 && jaum >= 2) flag = true;

    if(flag){
      for(int i=0; i<L; i++)
        cout << input[arr[i]];
      cout << '\n';
    }
  }

  for(int i=st; i<C; i++){
    arr[k] = i;
    func(k+1, i+1);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;
  for(int i=0; i<C; i++)
    cin >> input[i];
  sort(input, input+C);
  func(0, 0);
}