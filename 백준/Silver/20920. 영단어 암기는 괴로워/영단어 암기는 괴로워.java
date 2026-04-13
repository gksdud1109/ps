import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<String, Integer> wordCount = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String word = br.readLine();
            if (word.length() >= m) {
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
            }
        }

        List<String> words = new ArrayList<>(wordCount.keySet());

        words.sort((w1, w2) -> {
            int c1 = wordCount.get(w1);
            int c2 = wordCount.get(w2);

            if (c1 != c2) {
                return c2 - c1;
            }
            if (w1.length() != w2.length()) {
                return w2.length() - w1.length();
            }
            return w1.compareTo(w2);
        });

        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            sb.append(word).append("\n");
        }
        
        System.out.print(sb);
    }
}