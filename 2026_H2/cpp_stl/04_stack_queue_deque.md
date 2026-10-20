# 04. stack · queue · deque

[목차](../cpp_stl.md) · [Java 대응](../java_lib/04_stack_queue_deque.md)

각 자료구조의 조회 함수와 삭제 함수를 구분한다. C++의 pop 계열은 값을 반환하지 않는다.

## stack: push/top/pop/size/empty

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.top() << '\n';          // 20: 조회만
    int x = s.top();
    s.pop();                          // 삭제만
    cout << x << ' ' << s.size() << '\n'; // 20 1
    while (!s.empty()) {
        cout << s.top() << '\n';      // 10
        s.pop();
    }
    // 비어 있으면 top/pop을 호출하지 않는다.
}
```

## queue: push/front/back/pop

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << q.front() << ' ' << q.back() << '\n'; // 10 20
    int x = q.front();
    q.pop();                          // 앞 원소 삭제
    cout << x << ' ' << q.size() << '\n'; // 10 1
    while (!q.empty()) {
        cout << q.front() << '\n';    // 20
        q.pop();
    }
}
```

## deque: 양끝 삽입/삭제 · 인덱스 조회

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(10);                // {10}
    dq.push_back(20);                 // {10, 20}
    dq.push_front(5);                 // {5, 10, 20}
    cout << dq.front() << ' ' << dq.back() << '\n'; // 5 20
    dq.pop_front();                   // {10, 20}
    dq.pop_back();                    // {10}
    dq.push_back(30);                 // {10, 30}
    dq[1] = 25;                       // {10, 25}
    cout << dq.size() << '\n';        // 2
    for (int x : dq) cout << x << ' ';
    cout << '\n';
    dq.clear();
    cout << dq.empty() << '\n';       // 1
}
```

deque의 인덱스 조회는 O(1)이지만 메모리가 vector처럼 하나의 연속 구간은 아니다.
중간 삽입/삭제는 O(n). 양끝 연산과 인덱스 접근이 모두 필요할 때 선택할 수 있다.
5430의 R은 reverse를 매번 하지 말고 방향 boolean을 바꾸는 방법을 생각한다.

## 빈출 패턴: 괄호 검사

```cpp
#include <bits/stdc++.h>
using namespace std;

bool valid(const string& text) {
    stack<char> s;
    for (char c : text) {
        if (c == '(' || c == '[') s.push(c);
        else if (c == ')' || c == ']') {
            if (s.empty()) return false;
            char open = s.top(); s.pop();
            if (c == ')' && open != '(') return false;
            if (c == ']' && open != '[') return false;
        }
    }
    return s.empty();
}

int main() {
    cout << boolalpha << valid("([])") << '\n'; // true
    cout << valid("([)]") << '\n';             // false
}
```

## 빈출 패턴: 단조 스택

왼쪽에서 가장 가까운 더 큰 값의 위치. 후보의 인덱스를 저장한다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> height = {6, 9, 5, 7, 4};
    vector<int> answer(height.size());
    stack<int> s;
    for (int i = 0; i < static_cast<int>(height.size()); i++) {
        while (!s.empty() && height[s.top()] <= height[i]) s.pop();
        answer[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    for (int x : answer) cout << x << ' ';
    cout << '\n';                    // 0 0 2 2 4
}
```

각 인덱스는 한 번 들어가고 최대 한 번 빠져 전체 O(n)이다.
같은 높이를 답으로 인정하는 문제라면 `<`로 제거하는 등 정의에 맞춰 조건을 바꾼다.

## 닫고 다시 작성하기

- top/front를 먼저 읽고 pop하는 순서를 손에 익히기.
- 빈 스택에서 닫는 괄호가 들어오면 바로 실패 처리하기.
- 단조 스택에 값 대신 인덱스를 넣는 이유를 설명하기.
