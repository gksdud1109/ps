#include <bits/stdc++.h>
using namespace std;

int main(void){
  int a[3] = {1, 2, 3};
  do{
    for(int i=0; i<3; i++)
      cout << a[i];
    cout << '\n';
  }while(next_permutation(a, a+3)); // {1,2,3}에 대한 순열조합 생성

  int b[4] = {0,0,1,1}; // 중복된 수에 대해서도 정상적으로 순열 생성함.
  do{
    for(int i=0; i<4; i++){
      if(b[i] == 0)
        cout << i+1;
    }
    cout << '\n';
  }while(next_permutation(a, a+4)); // 4개에서 2개를 뽑는것과 같은 상황으로도 응용가능함.
}