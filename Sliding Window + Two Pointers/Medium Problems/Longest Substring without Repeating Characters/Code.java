//BRUTE FORCE : Using O(N^2) approach to generate all substrings and identifying using a hash table
// TC : O(N^2), SC : O(256) - 0 to 255 are the ASCII values for all the characters and symbols

import java.util.Arrays;

class Code {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int arr[] = new int[256];
        //hash arr to store characters and indices
        int ans = 0;
        Arrays.fill(arr, -1);
        while(right < n) {
            char x = s.charAt(right);
            if(arr[x] != -1) {
                //repeated
                if(arr[x] >= left) {
                    //if the repeated character is in the range of the substring taken - very important
                    left = arr[x] + 1;
                    //else no need to consider it as repeated
                }
            }
            int len = right - left + 1;
            ans = Math.max(ans, len);
            arr[x] = right;
            right++;
        }
        return ans;
    }
}

// TC : O(N)
// SC : O(256)