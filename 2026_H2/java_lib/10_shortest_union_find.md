# 10. 다익스트라 · 유니온 파인드

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/10_shortest_union_find.md)

기본 BFS/DFS를 먼저 익힌 뒤 보는 보충 주제다. 유니온 파인드는 기존 템플릿 외 추가 패턴이다.

## 다익스트라: 음수 간선이 없는 가중 그래프

힙에는 `[현재 거리, 정점]`을 넣고, 더 짧은 경로를 찾으면 갱신한 상태를 다시 넣는다.

```java
import java.util.*;

class Main {
    static class Edge {
        int to, weight;
        Edge(int to, int weight) { this.to = to; this.weight = weight; }
    }

    public static void main(String[] args) {
        int n = 4, start = 1;
        List<List<Edge>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        adj.get(1).add(new Edge(2, 2));
        adj.get(1).add(new Edge(3, 5));
        adj.get(2).add(new Edge(3, 1));
        adj.get(3).add(new Edge(4, 3));

        long inf = Long.MAX_VALUE / 4;
        long[] dist = new long[n + 1];
        Arrays.fill(dist, inf);
        PriorityQueue<long[]> pq = new PriorityQueue<>(
                Comparator.comparingLong(a -> a[0]));
        dist[start] = 0;
        pq.offer(new long[]{0, start});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long cost = cur[0];
            int u = (int) cur[1];
            if (cost != dist[u]) continue; // 더 짧은 거리로 이미 갱신된 상태
            for (Edge e : adj.get(u)) {
                long nextCost = cost + e.weight;
                if (nextCost >= dist[e.to]) continue;
                dist[e.to] = nextCost;
                pq.offer(new long[]{nextCost, e.to});
            }
        }
        System.out.println(dist[4] == inf ? "INF" : dist[4]); // 6
    }
}
```

- BFS처럼 처음 발견한 순간 방문을 확정하지 않는다. 이후 더 짧은 경로가 나올 수 있다.
- 음수 간선에는 적용하지 않는다. 위 예제의 가중치는 모두 0 이상이라는 전제다.
- 간선마다 힙 삽입이 생길 수 있는 구현이다. 보통의 단순 그래프에서 O((V+E) log V).
- 거리 합이 int 범위를 넘을 수 있어 long을 사용한다. inf도 가능한 최단거리보다 커야 한다.

## 유니온 파인드: 같은 집합인지 확인

경로 압축과 크기 기준 합치기를 사용한다. 연결 여부만 필요할 때 그래프 전체를 다시 탐색하지 않는다.

```java
class Main {
    static int[] parent, size;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static boolean union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) {
            int tmp = a; a = b; b = tmp;
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    public static void main(String[] args) {
        int n = 5;
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 1; i <= n; i++) { parent[i] = i; size[i] = 1; }
        union(1, 2);
        union(2, 3);
        System.out.println(find(1) == find(3)); // true
        System.out.println(find(1) == find(4)); // false
        System.out.println(union(1, 3));       // false: 이미 같은 집합
    }
}
```

두 최적화를 함께 쓰면 일련의 연산에서 분할상환 O(α(n))으로 거의 상수 시간이다.
합치기만 가능한 기본 구조이므로 간선 삭제·집합 분리는 별도 알고리즘이 필요하다.

## 닫고 다시 작성하기

- 1753에서 힙 원소를 정점 번호가 아니라 거리로 우선순위화하기.
- 시작점과 연결되지 않은 정점은 INF로 남는지 확인하기.
- 같은 집합을 다시 합칠 때 크기를 중복 증가시키지 않기.
