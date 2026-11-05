class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int currentHealth = health;
        int success =0;
        int attackIdx =0;
        
        int lastTime = attacks[attacks.length-1][0];
        
        for(int time = 1; time <= lastTime; time++){
            if(time == attacks[attackIdx][0]){
                currentHealth -= attacks[attackIdx][1];
                
                if(currentHealth <= 0) return -1;
                
                success = 0;
                attackIdx++;
            } else {
                currentHealth += bandage[1];
                success++;
                
                if(success == bandage[0]){
                    currentHealth += bandage[2];
                    success =0;
                }
                
                currentHealth = Math.min(currentHealth, health);
            }
        }
        
        return currentHealth;
    }
}