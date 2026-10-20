# 08. 완전탐색 · 백트래킹 · 비트마스크

[목차](../cpp_stl.md) · [Java 대응](../java_lib/08_backtracking.md)

부분집합은 2^n, 순열은 최대 n!이다. 구현 전에 입력 크기로 탐색 가능 여부부터 판단한다.
백트래킹은 선택 → 재귀 → 선택 복구 순서다.

## 순열: 서로 다른 n개 중 m개를 순서 있게 선택

```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 3, m = 2;
vector<int> path(m);
vector<bool> used(n + 1);

void dfs(int depth) {
    if (depth == m) {
        for (int x : path) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;
        path[depth] = i;
        dfs(depth + 1);
        used[i] = false;
    }
}

int main() {
    dfs(0); // 1 2 / 1 3 / 2 1 / 2 3 / 3 1 / 3 2
}
```

중복 선택이 허용되면 used 검사를 제거한다. 입력 값의 중복과 선택 중복은 구분한다.

## 조합: 순서 없이 선택

```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 4, m = 2;
vector<int> path(m);

void dfs(int depth, int start) {
    if (depth == m) {
        for (int x : path) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        path[depth] = i;
        dfs(depth + 1, i + 1);
    }
}

int main() {
    dfs(0, 1); // 1 2 / 1 3 / 1 4 / 2 3 / 2 4 / 3 4
}
```

다음 시작점을 i로 전달하면 같은 값을 다시 선택할 수 있는 중복 조합이 된다.

## 비트마스크: 집합 연산과 부분집합 열거

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int mask = 0, i = 1;
    mask |= 1 << i;
    cout << ((mask & (1 << i)) != 0) << '\n'; // 1: 포함
    mask ^= 1 << i;                   // 토글
    mask |= 1 << 2;
    mask &= ~(1 << 2);                // 제거
    cout << __builtin_popcount(static_cast<unsigned>(mask)) << '\n'; // 0

    vector<int> a = {1, 2, 3};
    int n = static_cast<int>(a.size()), target = 3, count = 0;
    for (int subset = 1; subset < (1 << n); subset++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (subset & (1 << j)) sum += a[j];
        }
        if (sum == target) count++;
    }
    cout << count << '\n';           // 2: {3}, {1,2}
}
```

위 int 열거 틀은 n<31인 작은 입력용이다. 빈 부분집합은 subset=0이므로 제외했다.
더 넓은 마스크는 `1ULL << i`, 개수는 GCC의 `__builtin_popcountll`을 쓸 수 있다.
이 내장 함수는 GCC 확장이다. C++20의 std::popcount와는 구분한다.
64비트라고 2^64개를 열거할 수 있는 것은 아니다. 전체 시간은 O(n·2^n)이다.

## next_permutation: 사전순 순열 · 조합

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3};
    sort(a.begin(), a.end());          // 모든 순열을 보려면 정렬부터
    do {
        for (int x : a) cout << x;
        cout << '\n';
    } while (next_permutation(a.begin(), a.end())); // 6개
    // 마지막에 false를 반환하면 배열은 오름차순으로 돌아간다.

    vector<int> choose = {0, 0, 1, 1}; // 4개 중 2개 선택
    do {
        for (int i = 0; i < 4; i++) {
            if (choose[i]) cout << i + 1;
        }
        cout << '\n';
    } while (next_permutation(choose.begin(), choose.end()));
    // 34, 24, 23, 14, 13, 12: 조합 6개
}
```

같은 값이 중복된 정렬 배열에서 시작하면 서로 다른 값 배열 순열을 한 번씩 생성한다.
예: {1,1,2}는 112, 121, 211이다.

## 닫고 다시 작성하기

- 15649와 15650을 used/start의 차이로 설명하기.
- 부분집합에서 공집합을 제외하는 위치를 확인하기.
- next_permutation을 정렬하지 않고 시작하면 놓치는 순열이 있는지 확인하기.
