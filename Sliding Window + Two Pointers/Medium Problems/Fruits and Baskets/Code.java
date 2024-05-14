import java.util.*;
class Code {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        int left = 0;
        int right = 0;
        int maxVal = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        while(right < n) {
            mp.put(fruits[right], mp.getOrDefault(fruits[right], 0) + 1);
            if(mp.size() > 2) {
                mp.put(fruits[left], mp.get(fruits[left])-1);
                if(mp.get(fruits[left]) == 0) {
                    mp.remove(fruits[left]);
                }
                left++;
            }
            if(mp.size() <= 2) {
                maxVal = Math.max(maxVal, right-left+1);
            }
            right++;
        }
        return maxVal;
    }
}