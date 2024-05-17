//Brute force : Subarray generation
// TC : O(N^2)
//SC : O(1)

// The problem can be converted into the Binary Subarray with Sum problem by considering the odd values as 1 and even values as 0 and just finding the subarrays with sum K

//Better approach : Optimal approach (Prefix sum approach) of count the number of subarrays with sum K
// TC : O(N)
// SC : O(N) - for hashing


// Optimal solution : Only because of binary values
//TC : O(2 * 2N)
// SC : O(1)
class Code {
    //function to find the number of subarrays that are <= goal
    public int solve(int[] nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.length;
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        while(right < n) {
            sum += (nums[right])%2;
            while(sum > goal) {
                sum = sum - (nums[left])%2;
                left += 1;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
}