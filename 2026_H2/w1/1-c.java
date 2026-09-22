import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 실행: java 2026_H2/w1/1-c.java
class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] t = new int[101]; // Java의 int 배열은 자동으로 0으로 초기화된다.

        // 현재 C++ 풀이의 시간 범위와 요금 계산 로직을 그대로 옮긴 버전.
        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            int inTime = Integer.parseInt(st.nextToken());
            int outTime = Integer.parseInt(st.nextToken());

            for (int j = inTime; j <= outTime; j++) {
                t[j]++;
            }
        }

        int fee = 0;
        for (int k = 0; k < t.length; k++) {
            int cur = t[k];
            if (cur == 1) fee += a;
            else if (cur == 2) fee += b;
            else if (cur == 3) fee += c;
        }

        System.out.println(fee);
    }
}
