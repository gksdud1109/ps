# 03. unordered_map · unordered_set · unordered_multiset

[목차](../cpp_stl.md) · [Java 대응](../java_lib/03_hash.md)

사용 신호: 키로 값 찾기, 빈도 세기, 중복 제거, 존재 확인.
unordered 계열의 순회 순서는 정렬순도 삽입순도 보장되지 않는다.
조회/삽입/키 삭제는 평균 O(1), 최악 O(n)이다. 문자열 해시 계산 비용은 길이에도 영향을 받는다.

## unordered_map: 주요 함수를 한 번에

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;
    m["apple"] = 3;                     // 저장
    m["banana"] = 2;
    m["apple"] = 5;                     // 덮어쓰기
    cout << m["apple"] << '\n';         // 5
    cout << m.count("pear") << '\n';    // 0: 존재 확인
    auto it = m.find("apple");
    if (it != m.end()) cout << it->second << '\n'; // 5
    cout << m.at("apple") << '\n';      // 5, 없는 키면 예외
    m.insert({"apple", 99});             // 이미 있으면 기존 값 유지
    m.emplace("pear", 1);               // 없으면 삽입
    ++m["banana"];                      // 빈도 증가 → 3
    cout << m.size() << ' ' << m.empty() << '\n'; // 3 0
    for (const auto& [key, value] : m) cout << key << ' ' << value << '\n';
    cout << m.erase("pear") << '\n';    // 삭제된 키 수 1
    cout << m.erase("none") << '\n';    // 0
    cout << m["missing"] << '\n';       // 0, 이 조회는 새 키를 삽입한다!
    cout << m.count("missing") << '\n'; // 1
    m.clear();
    cout << m.empty() << '\n';          // 1
}
```

`m[key]`가 새 키를 만드는 성질은 빈도 세기에는 편리하지만 단순 조회에서는 주의한다.
존재 확인만 필요하면 find/count, 반드시 있는 키의 값은 at을 사용할 수 있다.
순회 중 새 키 삽입은 재해시로 iterator를 무효화할 수 있다.

## unordered_set: 중복 없는 집합

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<string> s;
    cout << s.insert("apple").second << '\n'; // 1: 처음 삽입
    cout << s.insert("apple").second << '\n'; // 0: 중복
    s.insert("banana");
    cout << s.count("apple") << '\n';    // 1
    cout << (s.find("pear") != s.end()) << '\n'; // 0
    cout << s.size() << '\n';            // 2
    cout << s.erase("banana") << '\n';   // 1
    vector<string> sorted(s.begin(), s.end());
    sort(sorted.begin(), sorted.end());
    for (const auto& word : sorted) cout << word << '\n';
    s.clear();
    cout << s.empty() << '\n';           // 1
}
```

C++17 예제이므로 C++20의 contains 대신 find/count를 사용한다.

## unordered_multiset: 중복 허용 · 하나 삭제와 전부 삭제

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<int> ms = {10, 10, 20};
    cout << ms.count(10) << '\n';         // 2
    auto it = ms.find(10);
    if (it != ms.end()) ms.erase(it);     // 한 개만 삭제
    cout << ms.count(10) << '\n';         // 1
    ms.insert(20);
    cout << ms.erase(20) << '\n';         // 값 20 전부 삭제 → 2
    cout << ms.size() << '\n';            // 1
}
```

중복 개수에 따라 count/키 삭제 비용이 추가된다. find 실패로 나온 end()를 erase에 넘기지 않는다.

## 1620 패턴: 번호→이름 배열, 이름→번호 맵

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> i2s = {"", "Bulbasaur", "Ivysaur", "Pikachu"};
    unordered_map<string, int> s2i;
    for (int i = 1; i < static_cast<int>(i2s.size()); i++) s2i[i2s[i]] = i;
    vector<string> queries = {"3", "Ivysaur"};
    for (const string& query : queries) {
        if (isdigit(static_cast<unsigned char>(query[0]))) {
            cout << i2s[stoi(query)] << '\n'; // Pikachu
        } else {
            cout << s2i.at(query) << '\n';   // 2
        }
    }
}
```

## 닫고 다시 작성하기

- 단어가 처음 나오면 0에서 시작해 빈도 증가시키기.
- 없는 키를 find로 검사했을 때와 []로 읽었을 때 size가 어떻게 다른지 확인하기.
- 회사에 남아 있는 이름을 set으로 관리한 뒤 정렬해서 출력하기: 7785.
