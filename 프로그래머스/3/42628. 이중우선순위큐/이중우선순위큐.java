import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        // Key: 숫자, Value: 해당 숫자의 개수 (중복 허용을 위해)
        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (String op : operations) {
            String[] parts = op.split(" ");
            String cmd = parts[0];
            int num = Integer.parseInt(parts[1]);

            if (cmd.equals("I")) {
                map.put(num, map.getOrDefault(num, 0) + 1);
            } else {
                if (map.isEmpty()) continue; // 빈 큐면 무시

                // 최댓값 또는 최솟값 키 선택
                int key = (num == 1) ? map.lastKey() : map.firstKey();

                // 개수가 1개면 트리에서 제거, 2개 이상이면 카운트만 감소
                if (map.put(key, map.get(key) - 1) == 1) {
                    map.remove(key);
                }
            }
        }

        if (map.isEmpty()) {
            return new int[]{0, 0};
        }

        return new int[]{map.lastKey(), map.firstKey()};
    }
}