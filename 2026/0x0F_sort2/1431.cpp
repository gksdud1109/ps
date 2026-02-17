#include <bits/stdc++.h>
using namespace std;

int N;
string st;
vector<string> v;

bool cmp(string& a, string& b){
  int lena = a.size(), lenb = b.size();
  int suma =0, sumb = 0;
  if(lena != lenb) return lena < lenb;

  for(int i=0; i<lena; i++){ // 숫자만
    if(isdigit(a[i])) suma += (a[i] - '0');
  }

  for(int i=0; i<lenb; i++){ // 숫자만
    if(isdigit(b[i])) sumb += (b[i] - '0');
  }
  if(suma != sumb) return suma < sumb;
  return a < b; // 사전순
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> st;
    v.push_back(st);
  }

  sort(v.begin(), v.end(), cmp);
  for(auto i: v) cout << i << '\n';
}