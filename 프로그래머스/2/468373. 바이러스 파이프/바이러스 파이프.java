import java.util.*;

class Solution {
    int n, k;
    int maxInfected = 0;
    
    List<List<Integer>>[] components;
    
    public int solution(int n, int infection, int[][] edges, int k) {
        this.n = n;
        this.k = k;
        
        components = new ArrayList[4];
        for(int i=1; i<=3; i++){
            components[i] = new ArrayList<>();
        }
        
        List<Integer>[] adj1 = new ArrayList[n+1];
        List<Integer>[] adj2 = new ArrayList[n+1];
        List<Integer>[] adj3 = new ArrayList[n+1];
        
        for(int i=1; i<=n; i++){
            adj1[i] = new ArrayList<>();
            adj2[i] = new ArrayList<>();
            adj3[i] = new ArrayList<>();
        }
        for(int[] edge : edges){
            int u = edge[0], v = edge[1], type = edge[2];
            if (type == 1) { adj1[u].add(v); adj1[v].add(u); } 
            else if (type == 2) { adj2[u].add(v); adj2[v].add(u); } 
            else if (type == 3) { adj3[u].add(v); adj3[v].add(u); }
        }
        
        buildComponents(1, adj1);
        buildComponents(2, adj2);
        buildComponents(3, adj3);
        
        boolean[] initialInfected = new boolean[n+1];
        initialInfected[infection] = true;
        
        dfs(0, -1, initialInfected);
        
        return maxInfected;
    }
    
    private void buildComponents(int type, List<Integer>[] adj){
        boolean[] vis = new boolean[n+1];
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                List<Integer> comp = new ArrayList<>();
                Queue<Integer> q = new LinkedList<>();
                q.offer(i);
                vis[i] = true;
                comp.add(i);
                
                while(!q.isEmpty()){
                    int curr = q.poll();
                    for(int nxt : adj[curr]){
                        if(!vis[nxt]){
                            vis[nxt] = true;
                            q.offer(nxt);
                            comp.add(nxt);
                        }
                    }
                }
                
                // 혼자 있는 노드는 전염에 의미가 없으므로 2개 이상 연결된 덩어리만 저장
                if(comp.size() > 1){
                    components[type].add(comp);
                }
            }
        }
    }
    
    // DFS로 K번 동안 파이프를 여는 모든 경우의 수를 시뮬레이션
    private void dfs(int step, int lastType, boolean[] infected) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (infected[i]) count++;
        }
        maxInfected = Math.max(maxInfected, count);
        
        if (step == k) return;
        
        for (int type = 1; type <= 3; type++) {
            if (type == lastType) continue;
            
            boolean[] nextInfected = infected.clone();
            
            for (List<Integer> comp : components[type]) {
                boolean hasInfected = false;
                
                for (int u : comp) {
                    if (nextInfected[u]) {
                        hasInfected = true;
                        break;
                    }
                }
                
                if (hasInfected) {
                    for (int u : comp) {
                        nextInfected[u] = true;
                    }
                }
            }
            
            dfs(step + 1, type, nextInfected);
        }
    }
}