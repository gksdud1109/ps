# 07. 그래프 · 격자 BFS/DFS

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/07_graph.md)

사용 신호: 연결 여부, 영역 개수, 이동 횟수, 모든 이웃 방문.
여기서는 정점 번호는 1-index, 격자 좌표는 `(y, x)` 0-index로 통일한다.

## 인접 리스트 + DFS + BFS 거리

```java
import java.util.*;

class Main {
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] vis;

    static void dfs(int u) {
        vis[u] = true;
        System.out.print(u + " ");
        for (int v : adj.get(u)) {
            if (!vis[v]) dfs(v);
        }
    }

    static int[] bfs(int start, int n) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new ArrayDeque<>();
        dist[start] = 0;                 // 간선 개수 기준 거리
        q.offer(start);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (dist[v] != -1) continue;
                dist[v] = dist[u] + 1;   // 큐에 넣기 전에 방문 표시
                q.offer(v);
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        int n = 5;
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        int[][] edges = {{1, 2}, {1, 3}, {2, 4}};
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);      // 방향 그래프라면 이 줄 삭제
        }
        for (List<Integer> neighbors : adj) Collections.sort(neighbors);
        vis = new boolean[n + 1];
        dfs(1);                         // 1 2 4 3
        System.out.println();
        int[] dist = bfs(1, n);
        System.out.println(dist[4]);    // 2
        System.out.println(dist[5]);    // -1: 도달 불가
    }
}
```

DFS/BFS 자체는 인접 리스트에서 O(V + E). 방문순 정렬 비용은 별도다.
BFS의 최단거리 보장은 모든 간선의 이동 비용이 같을 때다.
경로가 매우 깊으면 재귀 DFS는 StackOverflowError가 날 수 있으므로 반복형을 고려한다.
반복형 DFS는 스택에 넣을 때 방문 처리하면 되지만 재귀 DFS와 방문순이 같다는 보장은 없다.

## 격자 BFS: 연결된 1의 영역 수와 크기

```java
import java.util.*;

class Main {
    static int[][] board = {
        {1, 1, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1}
    };
    static int n = board.length, m = board[0].length;
    static boolean[][] vis = new boolean[n][m];
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    static int bfs(int sy, int sx) {
        Queue<int[]> q = new ArrayDeque<>();
        vis[sy][sx] = true;
        q.offer(new int[]{sy, sx});
        int area = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            area++;
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur[0] + dy[dir]; // 시작점 sy/sx가 아니라 현재 위치!
                int nx = cur[1] + dx[dir];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (board[ny][nx] == 0 || vis[ny][nx]) continue;
                vis[ny][nx] = true;
                q.offer(new int[]{ny, nx});
            }
        }
        return area;
    }

    public static void main(String[] args) {
        List<Integer> areas = new ArrayList<>();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[y][x] == 0 || vis[y][x]) continue;
                areas.add(bfs(y, x)); // 새 BFS를 시작할 때 영역 하나 추가
            }
        }
        Collections.sort(areas);
        System.out.println(areas.size()); // 3
        System.out.println(areas);        // [1, 2, 3]
    }
}
```

2583처럼 빈칸이 이동 가능하면 통과 조건을 반대로 바꾼다.
2468은 매 높이마다 방문 배열을 초기화하고 `board[y][x] > h`인 칸만 통과한다. h=0도 확인한다.

## 격자 BFS: 최단 이동 거리

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[][] board = {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}};
        int n = board.length, m = board[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, -1);
        int[] dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};
        Queue<int[]> q = new ArrayDeque<>();
        if (board[0][0] == 1) {
            dist[0][0] = 0;
            q.offer(new int[]{0, 0});
        }
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cur[0] + dy[dir], nx = cur[1] + dx[dir];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (board[ny][nx] == 0 || dist[ny][nx] != -1) continue;
                dist[ny][nx] = dist[cur[0]][cur[1]] + 1;
                q.offer(new int[]{ny, nx});
            }
        }
        System.out.println(dist[n - 1][m - 1]); // 4번 이동
    }
}
```

미로 문제처럼 시작 칸까지 포함한 칸 수를 요구하면 시작 거리를 1로 설정한다.
거리 배열을 미방문 -1로 쓰면 별도 boolean 방문 배열 없이도 처리할 수 있다.
벽을 부술 수 있는 횟수 같은 상태가 추가되면 방문 배열 차원에도 그 상태를 포함해야 한다.

## 닫고 다시 작성하기

- 직사각형 2×5 입력으로 n/m, y/x를 뒤집지 않았는지 검사하기.
- 시작점이 막힌 경우, 전부 연결된 경우, 모든 칸이 떨어진 경우 검사하기.
- 영역 크기는 BFS 안에서, 영역 수는 BFS를 시작하는 바깥에서 세기.
