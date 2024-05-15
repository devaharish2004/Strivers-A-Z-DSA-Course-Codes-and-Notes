//BRUTE FORCE : GENERATE ALL SUBARRAYS
//TC : O(N*N)*26
//SC : O(26)

//BETTER APPROACH : SLIDING WINDOW + TWO POINTERS - TWO LOOPS EACH O(N) TIME + ADDITIONAL O(26) FOR UPDATING THE MAXFREQ


// MOST OPTIMIZED SOLUTION
// WE NEED NOT LOWER THE MAXFREQ, WHICH TAKES THE O(26) TIME, AS WE ARE ONLY INTERESTED IN THE HIGHER VALUES OF MAXFREQ - LOWERING DOES NOT PROVIDE THE ANSWER
// THE MAXFREQ WILL BE UPDATED AUTOMATICALLY DURING THE NEXT ITERATION
// REFER YT FOR MORE DETAILED EXPLANATION
// TC : O(N)
// SC : O(26)

class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int mostFreqLetter = 0;
        int left = 0;
        int max = 0;
        
        for(int right = 0; right < s.length(); right++){
            freq[s.charAt(right) - 'A']++;
            mostFreqLetter = Math.max(mostFreqLetter, freq[s.charAt(right) - 'A']);
            
            int lettersToChange = (right - left + 1) - mostFreqLetter;
            if(lettersToChange > k){
                freq[s.charAt(left) - 'A']--;
                left++;
            }
            
            max = Math.max(max, right - left + 1);
        }
        
        return max;
    }
}