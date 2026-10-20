# 01. 입출력 · 배열 · 문자열

[목차](../java_lib.md) · [C++ 대응](../cpp_stl/01_basics.md)

## BufferedReader + StringTokenizer + StringBuilder

입력 순서: 개수 → 정수 한 줄 → 공백이 포함된 문장 한 줄.
직접 입력할 예: 첫 줄 `3`, 둘째 줄 `3 1 2`, 셋째 줄 `hello world`.
출력은 `6`과 `hello world` 두 줄이다. 이 예제는 정수들이 한 줄에 있다는 전제다.

```java
import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Integer.parseInt(st.nextToken());
        }
        String line = br.readLine(); // 문장 전체: 공백도 유지
        StringBuilder sb = new StringBuilder();
        sb.append(sum).append('\n');
        sb.append(line).append('\n');
        System.out.print(sb);
    }
}
```

숫자가 여러 줄에 걸쳐 들어오면 문제의 입력 단위에 맞춰 토크나이저를 갱신한다.
아래처럼 빈 토큰을 만나면 다음 줄을 읽는 방법도 있다. 문자열 한 줄 전체를 읽는 용도와는 구분한다.

```java
import java.io.*;
import java.util.*;

class Main {
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) throw new EOFException();
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        int nextInt() throws IOException { return Integer.parseInt(next()); }
        long nextLong() throws IOException { return Long.parseLong(next()); }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        long sum = 0;
        for (int i = 0; i < n; i++) sum += fs.nextLong();
        System.out.println(sum); // 같은 입력 예제로는 6
    }
}
```

## 배열: 길이 · 초기화 · 복사 · 2차원 배열

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] a = {3, 1, 2};
        System.out.println(a.length);       // 3
        Arrays.fill(a, 7);                  // [7, 7, 7]
        Arrays.fill(a, 0, 2, 5);            // [5, 5, 7], 끝 인덱스 제외
        int[] b = Arrays.copyOf(a, a.length);
        b[0] = 99;                         // a는 변하지 않음
        int[] part = Arrays.copyOfRange(a, 1, 3);
        System.out.println(Arrays.toString(part)); // [5, 7]

        int[][] board = new int[2][3];      // 기본값 0
        for (int[] row : board) Arrays.fill(row, -1);
        int[][] copied = new int[board.length][];
        for (int i = 0; i < board.length; i++) {
            copied[i] = board[i].clone();   // 각 행까지 복사
        }
        copied[0][0] = 10;
        System.out.println(board[0][0]);   // -1

        char[] row = "1010".toCharArray();
        int cell = row[0] - '0';            // 문자 '1' → 정수 1
        long product = 1L * 100_000 * 100_000;
        System.out.println(cell + " " + product); // 1 10000000000
    }
}
```

- `int[] b = a`는 복사가 아니라 같은 배열을 가리킨다.
- `board.clone()`만 하면 행 배열은 공유된다. 격자를 독립적으로 복사하려면 행도 복사한다.
- `Arrays.fill(board, 같은행배열)`은 모든 행을 같은 배열로 만들어 버리므로 주의한다.

## String · StringBuilder

```java
import java.util.*;

class Main {
    public static void main(String[] args) {
        String s = "hello";
        System.out.println(s.length());           // 5
        System.out.println(s.charAt(1));          // e
        System.out.println(s.substring(1, 4));    // ell, 끝 인덱스 제외
        System.out.println(s.indexOf("ll"));      // 2, 없으면 -1
        System.out.println(s.contains("he"));     // true
        System.out.println(s.startsWith("he"));   // true
        System.out.println(s.endsWith("lo"));     // true
        System.out.println(s.equals("hello"));    // true
        System.out.println("a".compareTo("b") < 0); // true
        System.out.println(s.replace("l", "x"));  // hexxo, s 자체는 그대로
        System.out.println("  hi  ".trim());       // hi
        System.out.println("".isEmpty());          // true
        System.out.println(Integer.parseInt("25")); // 25
        System.out.println(String.valueOf(25));   // "25"
        System.out.println(Character.isDigit('2')); // true

        String[] words = "a.b.c".split("\\.");    // split 인자는 정규식
        System.out.println(Arrays.toString(words)); // [a, b, c]
        System.out.println(String.join("-", words)); // a-b-c

        StringBuilder sb = new StringBuilder("abc");
        sb.append('d');               // abcd
        sb.insert(1, 'X');            // aXbcd
        sb.setCharAt(0, 'A');         // AXbcd
        sb.deleteCharAt(1);           // Abcd
        sb.reverse();                // dcbA
        System.out.println(sb.toString());
        sb.setLength(0);              // 비우기
        System.out.println(sb.length()); // 0
    }
}
```

String은 불변이다. 반복해서 큰 문자열을 이어 붙일 때는 StringBuilder를 사용한다.
Java `substring(begin, end)`의 두 번째 인자는 길이가 아니라 끝 인덱스다.

## 닫고 다시 작성하기

- 2차원 방문 배열을 전부 `false`로, 거리 배열을 전부 `-1`로 초기화하기.
- `"10101"`을 정수 배열로 바꾸기.
- 공백이 포함된 문자열을 읽고 뒤집어서 출력하기.
