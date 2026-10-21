#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[101];

int dist[101][101];
pair<int, int> prePos[101][101];
string preCmd[101][101];

queue<pair<int, int>> Q;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
string command[] = {"D", "U", "L", "R"};

bool canMove(int y, int x) {
    return y >= 0 && y < n &&
           x >= 0 && x < m &&
           board[y][x] != '#';
}

// 현재 (y, x)에서 명령 cmd로 (ny, nx)에 도착
void addState(int y, int x, int ny, int nx, const string& cmd) {
    if (dist[ny][nx] != -1) return;

    dist[ny][nx] = dist[y][x] + 1;
    prePos[ny][nx] = {y, x};
    preCmd[ny][nx] = cmd;

    Q.push({ny, nx});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    pair<int, int> st = {-1, -1};
    pair<int, int> en = {-1, -1};

    for (int y = 0; y < n; y++) {
        cin >> board[y];
        fill(dist[y], dist[y] + m, -1);

        for (int x = 0; x < m; x++) {
            if (board[y][x] == 'S') st = {y, x};
            if (board[y][x] == 'E') en = {y, x};
        }
    }

    if (st.first == -1 || en.first == -1) {
        cout << -1 << '\n';
        return 0;
    }

    dist[st.first][st.second] = 0;
    Q.push(st);

    while (!Q.empty()) {
        auto [y, x] = Q.front();
        Q.pop();

        if (make_pair(y, x) == en) break;

        for (int dir = 0; dir < 4; dir++) {
            // 1. 일반 이동: 한 칸 이동
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (canMove(ny, nx)) {
                addState(y, x, ny, nx, command[dir]);
            }

            // 2. 슬라이드: 현재 위치부터 끝까지 이동
            ny = y;
            nx = x;

            while (canMove(ny + dy[dir], nx + dx[dir])) {
                ny += dy[dir];
                nx += dx[dir];

                // 도착점을 지나치지 않는다.
                if (board[ny][nx] == 'E') break;
            }

            // 한 칸도 움직이지 못한 명령은 제외
            if (ny == y && nx == x) continue;

            addState(y, x, ny, nx, "K" + command[dir]);
        }
    }

    if (dist[en.first][en.second] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    // 13913과 같은 방식으로 이전 위치를 따라간다.
    vector<string> instruction;

    for (auto cur = en; cur != st; cur = prePos[cur.first][cur.second]) {
        instruction.push_back(preCmd[cur.first][cur.second]);
    }

    reverse(instruction.begin(), instruction.end());

    cout << dist[en.first][en.second] << '\n';

    for (int i = 0; i < static_cast<int>(instruction.size()); i++) {
        if (i) cout << ' ';
        cout << instruction[i];
    }
    cout << '\n';
}