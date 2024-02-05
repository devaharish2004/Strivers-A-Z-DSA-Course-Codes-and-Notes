class Solution 
{
    //MEMOIZATION
    // public int solve(int ind, int max_ind, int[] nums, int n, int[][] dp)
    // {
    //     if(ind < 0) return 0;

    //     if(dp[ind][max_ind] != -1)
    //     {
    //         return dp[ind][max_ind];
    //     }

    //     int notPick = 0 + solve(ind-1, max_ind, nums, n, dp);
    //     int pick = 0;
    //     if(max_ind == n || nums[ind] < nums[max_ind])
    //     {
    //         pick = 1 + solve(ind-1, ind, nums, n, dp);
    //     }

    //     return dp[ind][max_ind] = Math.max(pick, notPick);
    // }
    // public int lengthOfLIS(int[] nums) 
    // {
    //     int n = nums.length;
    //     //store the index of the previous maximum element so that memoization will be easier
    //     // solve(ind, ind_of_max_val, nums, nums.length)
    //     int[][] dp = new int[n][n+1];
    //     for(int[] row : dp)
    //     {
    //         Arrays.fill(row, -1);
    //     }
    //     return solve(n-1, n, nums, n, dp);
    // }

    //TABULATION
    // public int lengthOfLIS(int[] nums) 
    // {
    //     int n = nums.length;
    //     int[][] dp = new int[n+1][n+1];

    //     //base case
    //     for(int max_ind = 0; max_ind <= n; max_ind++)
    //     {
    //         dp[0][max_ind] = 0;
    //     }

    //     for(int ind = 1; ind <= n; ind++)
    //     {
    //         for(int max_ind = 0; max_ind <= n; max_ind++)
    //         {
    //             int notPick = 0 + dp[ind-1][max_ind];
    //             int pick = 0;
    //             if(max_ind == n || nums[ind-1] < nums[max_ind])
    //             {
    //                 pick = 1 + dp[ind-1][ind-1];
    //             }

    //             dp[ind][max_ind] = Math.max(pick, notPick);
    //         }
    //     }

    //     return dp[n][n];


    // }

    //SPACE OPTIMIZATION
    // public int lengthOfLIS(int[] nums) 
    // {
    //     int n = nums.length;
    //     int[] prev = new int[n+1];
    //     int[] curr = new int[n+1];
    //     //base case
    //     for(int max_ind = 0; max_ind <= n; max_ind++)
    //     {
    //         prev[max_ind] = 0;
    //     }

    //     for(int ind = 1; ind <= n; ind++)
    //     {
    //         for(int max_ind = 0; max_ind <= n; max_ind++)
    //         {
    //             int notPick = 0 + prev[max_ind];
    //             int pick = 0;
    //             if(max_ind == n || nums[ind-1] < nums[max_ind])
    //             {
    //                 pick = 1 + prev[ind-1];
    //             }

    //             curr[max_ind] = Math.max(pick, notPick);
    //         }
    //         prev = curr.clone();
    //     }

    //     return curr[n];


 // }

    //Using O(N^2) approach through iteration and Space complexity O(N) - for printing the LIS
    public int lengthOfLIS(int[] nums)
    {
        int n = nums.length;
        int dp[] = new int[n];
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(nums[prev] < nums[i])
                dp[i] = Math.max(1 + dp[prev], dp[i]);
            }

            ans = Math.max(ans, dp[i]);
        }

        return ans;

    }



}