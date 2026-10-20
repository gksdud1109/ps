# 09. DP · 그리디

[목차](../cpp_stl.md) · [Java 대응](../java_lib/09_dp_greedy.md)

DP는 부분문제의 답을 저장해 연결한다. 그리디는 안전한 선택을 증명할 수 있을 때 결정을 확정한다.
정렬 후 고르기만 하면 모든 최적화 문제가 풀리는 것은 아니다.

## 1차원 DP: 1로 만들기

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<int> dp(n + 1);
    // dp[i]: i를 1로 만드는 최소 연산 횟수
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n] << '\n';            // 3
}
```

상태 정의 → 초기값 → 전이 → 계산 순서 → 정답 위치 순서로 정리한다.
위 예제는 시간 O(n), 공간 O(n)이다.

## 2차원 DP: 마지막 선택까지 저장

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<array<int, 3>> cost = {{26, 40, 83}, {49, 60, 57}, {13, 89, 99}};
    int n = static_cast<int>(cost.size());
    vector<array<int, 3>> dp(n);
    // dp[i][c]: 0~i번 집을 칠하고 i번 집 색이 c일 때 최소 비용
    dp[0] = cost[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n'; // 96
}
```

직전 색을 알아야 다음 집의 선택이 가능하므로 dp[i] 하나로 상태를 압축하지 않는다.
2차원 상태가 필요한 이유부터 설명하고 점화식을 쓴다.

## 0/1 배낭: 물건 하나를 최대 한 번

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> weight = {6, 4, 3, 5}, value = {13, 8, 6, 12};
    int capacity = 7;
    vector<int> dp(capacity + 1);
    // dp[w]: 지금까지 본 물건으로 총 무게 w 이하에서 얻을 최대 가치
    for (int i = 0; i < static_cast<int>(weight.size()); i++) {
        for (int w = capacity; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    cout << dp[capacity] << '\n';      // 14
}
```

무게를 내림차순으로 갱신해야 이번 물건을 반복 사용하지 않는다. 시간 O(n·capacity).
정확히 w를 채우는 상태라면 도달 불가 상태의 초기값과 전이 검사를 별도로 설계한다.
현재 저장소의 12865가 greedy 폴더에 있어도 이 문제의 분류는 DP다.

## 그리디: 종료가 빠른 회의부터 선택

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> meetings = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    // {시작, 종료}: 종료 오름차순, 같으면 시작 오름차순
    sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    int end = INT_MIN, count = 0;
    for (auto [start, finish] : meetings) {
        if (start < end) continue;
        count++;
        end = finish;
    }
    cout << count << '\n';            // 3
}
```

같은 수의 회의를 골랐을 때 마지막 종료가 빠를수록 이후 선택의 여지가 줄지 않는다.
회의별 보상의 합을 최대화하는 문제에서는 이 규칙이 성립하지 않을 수 있다.
큰 동전부터 고르는 규칙도 모든 동전 체계에 통하는 것은 아니다.

## 닫고 다시 작성하기

- dp 칸의 의미를 주석 한 줄로 적은 다음에 코드를 작성하기.
- 14501에서 상담 선택/건너뛰기를 두 전이로 표현하기.
- 배낭을 무게 오름차순으로 갱신하면 어떤 물건이 재사용되는지 설명하기.
- 그리디 기준의 반례를 스스로 찾아보고, 맞는 기준의 근거를 설명하기.
