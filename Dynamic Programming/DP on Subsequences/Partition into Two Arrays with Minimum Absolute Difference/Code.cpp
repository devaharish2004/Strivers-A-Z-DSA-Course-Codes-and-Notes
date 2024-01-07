int minSubsetSumDifference(vector<int>& nums, int n)
{
	// Write your code here.
	int sum = 0;
	//get the total sum of the array
	for(int i = 0; i < n; i++)
	{
		sum += nums[i];
	}
	//get the dp table for the subset sum problem
	vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	for(int i = 0; i < n; i++)
	{
		dp[i][0] = true;
	}
	if(nums[0] <= sum)
	{
		dp[0][nums[0]] = true;
	}

	for(int i = 1; i < n; i++)
	{
		for(int target = 1; target <= sum; target++)
		{
			bool notpick = dp[i-1][target];
			bool pick = false;
			if(nums[i] <= target)
			{
				pick = dp[i-1][target - nums[i]];
			}
			dp[i][target] = pick || notpick;
		}
	}

	//find the another subset sum from totalsum and find the minimum abs diff
	int mini = 1e9;
	for(int s1 = 0; s1 <= sum/2; s1++)
	{
		if(dp[n-1][s1] == true)
		{
			int s2 = sum - s1;
			mini = min(mini, abs(s2-s1));
		}
	}

	return mini;
}
