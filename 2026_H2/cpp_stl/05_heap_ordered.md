# 05. priority_queue · set · multiset · map

[목차](../cpp_stl.md) · [Java 대응](../java_lib/05_heap_ordered.md)

최댓값/최솟값을 계속 꺼내면 힙, 정렬된 키의 이웃까지 탐색하면 트리 기반 컨테이너를 쓴다.

## priority_queue: 최대 힙 · 최소 힙 · 사용자 기준

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    maxHeap.push(10); maxHeap.push(2); maxHeap.push(5);
    cout << maxHeap.top() << '\n';    // 10
    maxHeap.pop();
    cout << maxHeap.top() << '\n';    // 5
    cout << maxHeap.size() << '\n';   // 2

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10); minHeap.push(2); minHeap.push(5);
    while (!minHeap.empty()) {
        cout << minHeap.top() << ' ';  // 2 5 10
        minHeap.pop();
    }
    cout << '\n';

    using P = pair<long long, int>;   // {거리, 정점}: 앞 필드부터 비교
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({5, 2}); pq.push({3, 1});
    auto [cost, node] = pq.top(); pq.pop();
    cout << cost << ' ' << node << '\n'; // 3 1

    auto cmp = [](int a, int b) {
        long long aa = abs(static_cast<long long>(a));
        long long bb = abs(static_cast<long long>(b));
        if (aa != bb) return aa > bb;
        return a > b;                // 같은 절댓값이면 작은 수 먼저
    };
    priority_queue<int, vector<int>, decltype(cmp)> absHeap(cmp);
    absHeap.push(1); absHeap.push(-1);
    cout << absHeap.top() << '\n';   // -1
}
```

- top O(1), push/pop O(log n). 중복 원소를 저장할 수 있다.
- 힙 비교 함수에서 `true`는 첫 원소의 우선순위가 뒤라는 의미다. sort의 앞세우기와 혼동하지 않는다.
- 정렬순으로 순회하려면 top/pop을 반복한다. iterator나 인덱스 접근은 제공하지 않는다.

## set: 중복 없는 정렬된 값 · lower_bound/upper_bound

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {10, 20, 30};
    s.insert(20);                     // 중복 무시
    cout << s.count(20) << '\n';     // 1
    cout << *s.begin() << ' ' << *s.rbegin() << '\n'; // 10 30
    auto lo = s.lower_bound(20);      // >= 20인 첫 원소
    auto hi = s.upper_bound(20);      // > 20인 첫 원소
    if (lo != s.end()) cout << *lo << '\n'; // 20
    if (hi != s.end()) cout << *hi << '\n'; // 30
    auto it = s.upper_bound(25);
    if (it != s.begin()) cout << *prev(it) << '\n'; // <=25인 최대값 20
    auto found = s.find(20);
    if (found != s.end()) s.erase(found);
    for (int x : s) cout << x << ' ';
    cout << '\n';                   // 10 30
    s.clear();
    cout << s.empty() << '\n';       // 1
}
```

삽입/키 삭제/키 탐색/멤버 bound는 O(log n). 빈 집합에서 begin/rbegin을 역참조하지 않는다.
set/map에는 전역 lower_bound보다 컨테이너의 멤버 lower_bound를 사용한다.
트리 iterator를 전역 알고리즘으로 이분 탐색하면 iterator 이동이 선형이 될 수 있다.

## multiset: 중복 허용 · 하나 삭제 vs 전체 삭제

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms = {10, 10, 20};
    auto it = ms.find(10);
    if (it != ms.end()) ms.erase(it); // 10 하나만 삭제
    cout << ms.count(10) << '\n';    // 1
    ms.insert(20);
    cout << ms.erase(20) << '\n';    // 모든 20 삭제 → 2
    auto range = ms.equal_range(10);  // 10인 원소들의 [첫 위치, 끝 다음)
    for (auto cur = range.first; cur != range.second; ++cur) {
        cout << *cur << '\n';       // 10
    }
}
```

개수를 모두 세거나 같은 키를 전부 지울 때는 일치 원소 수만큼의 비용도 든다.

## map: 키 오름차순 + 값

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m;
    m[20] = "twenty";
    m[10] = "ten";
    m[30] = "thirty";
    cout << m.at(20) << '\n';         // twenty
    auto it = m.lower_bound(15);      // >=15인 첫 키
    if (it != m.end()) cout << it->first << ' ' << it->second << '\n'; // 20 twenty
    for (const auto& [key, value] : m) cout << key << ' ' << value << '\n';
    m.erase(20);
    cout << m.count(20) << '\n';      // 0
}
```

map은 키 정렬이 필요한 경우, unordered_map은 정렬 없이 빠른 키 조회가 필요한 경우에 사용한다.
map의 []도 없는 키를 삽입한다. multiset과 달리 map은 같은 키가 하나뿐이다.

## 닫고 다시 작성하기

- 기본 priority_queue가 최대 힙이라는 점을 Java와 비교하기.
- set에서 x 이상 최소값, x 이하 최대값을 각각 구하기.
- multiset의 erase(값)와 erase(iterator)를 구분하기.
