# 10. 다익스트라 · 유니온 파인드

[목차](../cpp_stl.md) · [Java 대응](../java_lib/10_shortest_union_find.md)

기본 BFS/DFS 뒤에 확인할 보충 주제다. 유니온 파인드는 기존 예제 외 추가한 패턴이다.

## 다익스트라: 음수 간선이 없는 가중 그래프

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n = 4, start = 1;
    vector<vector<pair<int, int>>> adj(n + 1); // {다음 정점, 가중치}
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 3});

    const ll inf = LLONG_MAX / 4;
    vector<ll> dist(n + 1, inf);
    using P = pair<ll, int>;          // {거리, 정점}
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost != dist[u]) continue; // 더 짧은 거리로 이미 갱신된 상태
        for (auto [v, weight] : adj[u]) {
            ll nextCost = cost + weight;
            if (nextCost >= dist[v]) continue;
            dist[v] = nextCost;
            pq.push({nextCost, v});
        }
    }
    if (dist[4] == inf) cout << "INF\n";
    else cout << dist[4] << '\n';      // 6
}
```

- 모든 가중치가 0 이상이어야 한다. 음수 간선에는 적용하지 않는다.
- BFS처럼 첫 발견 시점에 방문을 확정하지 않는다. 더 짧은 거리로 갱신될 수 있다.
- 이 구현은 간선마다 힙 삽입이 생길 수 있다. 보통의 단순 그래프에서 O((V+E) log V).
- 가능한 경로 합보다 inf가 큰지 확인하고 long long으로 덧셈한다.

## 유니온 파인드: 집합 합치기 · 같은 집합 확인

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // 경로 압축
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];           // 작은 집합을 큰 집합 밑으로
        return true;
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    cout << boolalpha << (dsu.find(1) == dsu.find(3)) << '\n'; // true
    cout << (dsu.find(1) == dsu.find(4)) << '\n';             // false
    cout << dsu.unite(1, 3) << '\n';                         // false
}
```

경로 압축 + 크기 기준 합치기를 함께 쓰면 분할상환 O(α(n))으로 거의 상수 시간이다.
이미 같은 집합일 때 size를 또 더하지 않는다. 간선 삭제/집합 분리는 기본 구조의 범위 밖이다.

## 닫고 다시 작성하기

- 우선순위 큐의 pair 순서가 {거리, 정점}인지 확인하기.
- 도달 불가 정점이 inf로 남는지 확인하기.
- 같은 정점 쌍을 여러 번 합쳐도 집합 크기가 바뀌지 않는지 검사하기.
