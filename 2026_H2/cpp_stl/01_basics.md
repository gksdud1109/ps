# 01. 입출력 · 배열 · 문자열

[목차](../cpp_stl.md) · [Java 대응](../java_lib/01_basics.md)

## cin/cout/getline

직접 입력할 예: 첫 줄 `3`, 둘째 줄 `3 1 2`, 셋째 줄 `hello world`.
출력은 `6`과 `hello world` 두 줄이다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line); // 공백 포함 문장 전체
    cout << sum << '\n' << line << '\n';
}
```

`cin >>`는 공백/개행을 구분자로 사용한다. 뒤에 getline을 섞을 때 남은 개행을 처리한다.
`getline(cin >> ws, line)`도 가능하지만 앞쪽 공백/빈 줄까지 제거하므로 입력 의미를 확인한다.
반복 출력에서는 불필요한 flush를 하는 endl 대신 `'\n'`을 사용한다.

## 배열: 초기화 · 복사 · 합계 · 2차원 배열

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    array<int, 3> a = {3, 1, 2};
    a.fill(7);                          // {7, 7, 7}
    fill(a.begin(), a.begin() + 2, 5);   // {5, 5, 7}
    auto b = a;                         // 독립적인 값 복사
    b[0] = 99;
    cout << a[0] << ' ' << a.size() << '\n'; // 5 3
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n'; // 17
    cout << *min_element(a.begin(), a.end()) << '\n';    // 5
    cout << *max_element(a.begin(), a.end()) << '\n';    // 7

    int board[2][3];
    for (int y = 0; y < 2; y++) fill(board[y], board[y] + 3, -1);
    vector<vector<int>> grid(2, vector<int>(3, -1));
    auto copied = grid;
    copied[0][0] = 10;
    cout << grid[0][0] << '\n';          // -1
    char c = '7';
    cout << c - '0' << '\n';            // 7
    long long product = 1LL * 100000 * 100000;
    cout << product << '\n';            // 10000000000
}
```

- fill의 범위는 `[begin, end)`다. 2차원 기본 배열은 행마다 초기화하면 경계가 명확하다.
- min/max_element는 iterator를 반환하므로 `*`로 값을 읽는다. 빈 범위는 역참조하지 않는다.
- accumulate의 초기값을 0LL로 주면 합산 자료형이 long long이 된다.
- 크기가 큰 지역 배열은 스택 제한을 고려해 vector나 전역 저장을 사용한다.
- memset의 세 번째 인자는 원소 수가 아니라 바이트 수다. 일반 정수값 채우기는 fill이 명확하다.

## string: 조회 · 부분문자열 · 삽입/삭제 · 변환

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello";
    cout << s.size() << '\n';             // 5
    cout << s[1] << '\n';                 // e
    cout << s.substr(1, 3) << '\n';       // ell: 시작 위치, 길이
    auto pos = s.find("ll");
    if (pos != string::npos) cout << pos << '\n'; // 2
    cout << (s.find("zz") == string::npos) << '\n'; // 1
    cout << (s == "hello") << '\n';       // 1: 내용 비교 가능
    cout << (string("a") < string("b")) << '\n'; // 1: 사전순

    s += "!";                             // hello!
    s.push_back('?');                      // hello!?
    s.pop_back();                          // hello!
    s.replace(1, 2, "XX");                // hXXlo!: 위치, 길이, 새 문자열
    s.insert(0, "say ");                  // say hXXlo!
    s.erase(0, 4);                         // hXXlo!
    reverse(s.begin(), s.end());           // !olXXh
    cout << s << '\n';
    cout << stoi("25") << ' ' << stoll("10000000000") << '\n';
    cout << to_string(25) << '\n';
    cout << (isdigit(static_cast<unsigned char>('2')) != 0) << '\n'; // 1
    s.clear();
    cout << s.empty() << '\n';             // 1
}
```

substr의 두 번째 인자는 Java와 달리 끝 인덱스가 아니라 길이다.
string도 연속 저장이므로 중간 삽입/삭제는 O(n)이다.
find의 반환형은 부호 없는 크기 타입이다. 없는 경우는 -1 대신 string::npos로 비교한다.

## stringstream: 문자열을 공백/구분자로 나누기

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stringstream words("10 20 30");
    int x, sum = 0;
    while (words >> x) sum += x;
    cout << sum << '\n';                  // 60

    stringstream csv("apple,banana,pear");
    string token;
    vector<string> parts;
    while (getline(csv, token, ',')) parts.push_back(token);
    for (const auto& part : parts) cout << part << '\n';
}
```

## 닫고 다시 작성하기

- 2차원 거리 배열을 모두 -1로 초기화하기.
- 문자열 숫자와 정수 사이를 변환하기.
- 공백 포함 입력을 읽고 특정 부분문자열이 있는지 확인하기.
