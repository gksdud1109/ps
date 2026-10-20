# 02. vector · list · pair/tuple · 정렬

[목차](../cpp_stl.md) · [Java 대응](../java_lib/02_list_sort.md)

## vector: 주요 함수를 한 번에

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 30};
    v.push_back(40);                   // {10, 30, 40}
    v.insert(v.begin() + 1, 20);      // {10, 20, 30, 40}
    cout << v[1] << '\n';            // 20
    v[1] = 25;
    cout << v.front() << ' ' << v.back() << '\n'; // 10 40
    cout << v.size() << ' ' << v.empty() << '\n'; // 4 0
    v.erase(v.begin() + 1);          // {10, 30, 40}
    auto it = find(v.begin(), v.end(), 30);
    if (it != v.end()) v.erase(it);  // {10, 40}, 값 검색은 O(n)
    v.pop_back();                    // {10}, pop은 반환값 없음
    v.resize(3, 7);                  // {10, 7, 7}
    auto copied = v;                 // 독립 복사
    copied.clear();
    cout << v.size() << '\n';        // 3
    v.reserve(100);                  // 용량 확보. size는 여전히 3
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
```

`reserve(n)`은 원소 n개를 만드는 함수가 아니다. `v[i]`로 쓰려면 size 범위 안이어야 한다.
재할당이 발생하면 기존 iterator/참조가 무효화된다. erase 뒤 위치들의 iterator도 주의한다.
빈 vector의 front/back/pop_back을 호출하지 않는다.

## list: iterator 앞 삽입 · 해당 원소 삭제

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<char> text = {'a', 'b'};
    auto cursor = text.end();        // a b |
    if (cursor != text.begin()) --cursor; // a | b
    text.insert(cursor, 'x');        // a x | b, 기존 cursor는 여전히 b
    if (cursor != text.begin()) {
        auto target = prev(cursor);  // x
        cursor = text.erase(target); // a | b, 삭제 다음 위치 반환
    }
    if (cursor != text.end()) ++cursor;
    for (char c : text) cout << c;
    cout << '\n';                   // ab
}
```

위치를 이미 알고 있는 경우 삽입/삭제 O(1). list에는 `text[i]`가 없다.
begin에서 --하거나 end를 역참조/삭제하지 않는다. list 정렬은 `text.sort()`를 사용한다.

## pair/tuple: 앞 필드부터 사전식 비교

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> point = {2, 3};
    auto [y, x] = point;              // C++17 구조적 바인딩
    cout << point.first << ' ' << point.second << '\n'; // 2 3
    cout << y << ' ' << x << '\n';   // 2 3
    tuple<int, int, string> t = {90, 70, "Kim"};
    cout << get<0>(t) << ' ' << get<2>(t) << '\n'; // 90 Kim
    vector<pair<int, int>> v = {{2, 1}, {1, 9}, {1, 3}};
    sort(v.begin(), v.end());         // {1,3}, {1,9}, {2,1}
    for (auto [a, b] : v) cout << a << ' ' << b << '\n';
}
```

## sort/reverse/unique + 다중 조건 비교

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int kor, eng, math;
};

int main() {
    vector<int> a = {3, 1, 2, 2};
    sort(a.begin(), a.end());             // {1, 2, 2, 3}
    a.erase(unique(a.begin(), a.end()), a.end()); // {1, 2, 3}
    sort(a.begin(), a.end(), greater<int>());    // {3, 2, 1}
    reverse(a.begin(), a.end());          // {1, 2, 3}
    cout << count(a.begin(), a.end(), 2) << '\n'; // 1, count는 O(n)

    vector<Student> stu = {
        {"Kim", 90, 70, 80}, {"Lee", 90, 60, 80}, {"Ahn", 90, 60, 90}
    };
    sort(stu.begin(), stu.end(), [](const Student& x, const Student& y) {
        if (x.kor != y.kor) return x.kor > y.kor;
        if (x.eng != y.eng) return x.eng < y.eng;
        if (x.math != y.math) return x.math > y.math;
        return x.name < y.name;
    });
    for (const auto& s : stu) cout << s.name << '\n'; // Ahn, Lee, Kim
}
```

- sort는 O(n log n), 안정 정렬이 필요하면 stable_sort를 사용한다.
- unique는 연속 중복만 압축하므로 전체 중복 제거는 먼저 정렬한다.
- 비교 함수에서 같은 값끼리는 false여야 한다. `<=`를 사용하지 않는다.
- 기존 10825의 `tuple(-kor, eng, -math, name)` 방식도 같은 우선순위를 표현한다.

## 닫고 다시 작성하기

- vector에서 인덱스 삭제와 값 검색 후 삭제를 각각 구현하기.
- 점수 내림차순, 이름 오름차순 정렬하기.
- list iterator가 삭제 뒤 어디를 가리켜야 하는지 설명하기.
