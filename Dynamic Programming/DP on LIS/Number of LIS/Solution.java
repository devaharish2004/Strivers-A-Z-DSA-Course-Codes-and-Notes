import java.util.Arrays;

class Solution 
{
    public int findNumberOfLIS(int[] nums) 
    {
        int n = nums.length;

        int maxi = Integer.MIN_VALUE;
        
        int[] dp = new int[n];
        int[] cnt = new int[n];
        
        // dp[i] represents the length of LIS ending at index i
        // cnt[i] represents the number of subsequences ending at i that have the length dp[i]
        Arrays.fill(dp, 1);
        Arrays.fill(cnt, 1);
        
        for(int ind = 0; ind < n; ind++)
        {
            for(int prev = 0; prev < ind; prev++)
            {
                if(nums[ind] > nums[prev])
                {
                    if(dp[prev] + 1 > dp[ind])
                    {
                        dp[ind] = dp[prev] + 1;
                        cnt[ind] = cnt[prev];
                    }
                    else if(dp[prev] + 1 == dp[ind])
                    {
                        cnt[ind] = cnt[ind] + cnt[prev];
                    }
                }
            }
            maxi = Math.max(dp[ind], maxi);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
            {
                ans += cnt[i];
            }
        }

        return ans;

    }

}

/*
 * TC : ~ O(N*N) + O(N)
 * SC : O(2N) ~ O(N)
 */ 