#include <bits/stdc++.h>
using namespace std;

/*
unorderd_set
- 중복을 허용하지 않음
- find()는 iterator를 반환, 값이 없다면 end()를 반환
- note: 크기순서 혹은 삽입순서로 위치해 있지 않는다!
*/
void unordered_set_example(){
  unordered_set<int> s;
  s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15}
  s.insert(-10); // {-10, 100, 15}
  cout << s.erase(100) << '\n'; // {-10, 15}, 1
  cout << s.erase(20) << '\n'; // {-10, 15}, 0
  if(s.find(15) != s.end()) cout << "15 in s\n";
  else cout << "15 not in s\n";
  cout << s.size() << '\n'; // 2
  cout << s.count(50) << '\n'; // 0
  for(auto e : s) cout << e << ' ';
  cout << '\n';
}

/*
unorderd_multiset
- 중복 허용
- erase()시에 중복되는 원소 전부 지워짐
- 하나만 지우고 싶을땐 ms.erase(ms.find(-10))로 iterator를 erase의 인자로 넘기면 된다.
*/
void unordered_multiset_example(){
  unordered_multiset<int> ms;
  ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
  ms.insert(-10); ms.insert(15); // {-10, -10, 100, 15, 15}
  cout << ms.size() << '\n'; // 5
  for(auto e : ms) cout << e << ' ';
  cout << '\n';
  cout << ms.erase(15) << '\n'; // {-10, -10, 100} 2
  ms.erase(ms.find(-10)); // {-10, 100}
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100) << '\n'; // 2
}

/*
unordered_map
- 키와 값의 매칭
- 중복 키 허용안됨
*/
void unordered_map_example(){
  unordered_map<string, int> m;
  m["hi"] = 123;
  m["bkd"] = 1000;
  m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
  cout << m.size() << '\n'; // 3
  m["hi"] = -7; // ("hi", -7), ("bkd", 1000), ("gogo", 165)
  if(m.find("hi") != m.end()) cout << "hi in m \n";
  else cout << "hi not int m \n";
  m.erase("bkd"); // ("hi", 123), ("gogo", 165)
  for(auto e : m)
    cout << e.first << ' ' << e.second << '\n';
}

int main(){
  unordered_set_example();
  cout << "=====\n";
  unordered_multiset_example();
  cout << "=====\n";
  unordered_map_example();
}