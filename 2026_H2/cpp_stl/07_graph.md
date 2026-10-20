# 07. 그래프 · 격자 BFS/DFS

[목차](../cpp_stl.md) · [Java 대응](../java_lib/07_graph.md)

정점 번호는 1-index, 격자는 `(y, x)` 0-index로 통일한다.

## 인접 리스트 + DFS + BFS 거리

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    cout << u << ' ';
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;  // 큐에 넣기 전에 방문 표시
            q.push(v);
        }
    }
    return dist;
}

int main() {
    int n = 5;
    adj.resize(n + 1);
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}};
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);         // 방향 그래프라면 이 줄 삭제
    }
    for (auto& neighbors : adj) sort(neighbors.begin(), neighbors.end());
    vis.assign(n + 1, false);
    dfs(1);                         // 1 2 4 3
    cout << '\n';
    auto dist = bfs(1, n);
    cout << dist[4] << '\n';        // 2
    cout << dist[5] << '\n';        // -1: 도달 불가
}
```

DFS/BFS 자체는 인접 리스트에서 O(V + E), 방문순 정렬 비용은 별도다.
재귀가 깊어질 수 있으면 스택 오버플로를 고려해 반복형 DFS를 사용한다.
반복형에서 스택에 넣을 때 방문 처리하면 중복 삽입을 막을 수 있지만 재귀와 방문순은 다를 수 있다.
BFS의 최단거리 보장은 모든 간선의 이동 비용이 같을 때다.

## 격자 BFS: 영역 수와 크기

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board = {{1, 1, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}};
int n = 3, m = 4;
vector<vector<bool>> vis(n, vector<bool>(m));
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    vis[sy][sx] = true;
    q.push({sy, sx});
    int area = 0;
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir]; // 현재 위치에서 이동
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 0 || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    return area;
}

int main() {
    vector<int> areas;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board[y][x] == 0 || vis[y][x]) continue;
            areas.push_back(bfs(y, x));
        }
    }
    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';     // 3
    for (int area : areas) cout << area << ' ';
    cout << '\n';                    // 1 2 3
}
```

빈칸이 이동 가능한 문제면 통과 조건을 바꾼다. 영역 수는 바깥에서 BFS를 새로 시작할 때 증가시킨다.
2468은 각 높이마다 vis를 초기화하고 `board[y][x] > h`인 칸만 통과한다. h=0도 검사한다.

## 격자 BFS: 최단 이동 거리

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> board = {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}};
    int n = 3, m = 3;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    if (board[0][0] == 1) {
        dist[0][0] = 0;
        q.push({0, 0});
    }
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 0 || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << dist[n - 1][m - 1] << '\n'; // 4번 이동
}
```

시작 칸을 포함한 칸 수를 요구하면 시작 거리를 1로 둔다.
벽 부수기 횟수 같은 추가 상태가 있으면 방문 배열에도 그 상태 차원을 포함한다.

## 닫고 다시 작성하기

- 이웃 좌표를 시작점이 아니라 큐에서 꺼낸 현재 위치로 계산하기.
- 방문 검사에서 `막힌 칸 || 이미 방문`이면 건너뛰기.
- 직사각형 격자, 시작점이 막힌 경우, 도달 불가를 검사하기.
