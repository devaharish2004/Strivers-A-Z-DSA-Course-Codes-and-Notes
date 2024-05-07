class Solution {
    public int longestOnes(int[] nums, int k) {
        //sliding window + two pointer O(N) optimal approach
        int n = nums.length;
        int left = 0;
        int right = 0;
        int zeros = 0;
        int maxlen = 0;
        while(right < n) {
            if(nums[right] == 0) {
                zeros++;
            }
            if(zeros > k) {
                //trim left by 1 to keep the maxlen, and update it only when zeros <= k
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            else {
                int len = right-left+1;
                maxlen = Math.max(maxlen, len);
            }
            right++;
        }
        return maxlen;
    }
}