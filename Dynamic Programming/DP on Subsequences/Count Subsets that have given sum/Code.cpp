//MEMOIZATION
// int MOD = 1e9+7;
// int solve(vector<int>& arr, int index, int target, vector<vector<int>>&dp)
// {
// 	if(target == 0)
// 	{
// 		return dp[index][target] = 1;
// 	}
	
// 	if(index == 0)
// 	{
// 		if(target == arr[0])
// 		{
// 			return dp[index][target] = 1;
// 		}
// 		else
// 		{
// 			return dp[index][target] = 0;
// 		}
// 	}

// 	if(dp[index][target] != -1)
// 	{
// 		return dp[index][target];
// 	}

// 	int not_pick = solve(arr, index-1, target, dp);

// 	int pick = 0;

// 	if(arr[index] <= target)
// 	{
// 		pick = solve(arr, index - 1, target - arr[index], dp);
// 	}

// 	return dp[index][target] = (pick + not_pick)%MOD;
// }


// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	int n = arr.size();
// 	vector<vector<int>> dp(n, vector<int>(k+1,-1));
// 	int ans = solve(arr,n-1,k, dp);
// 	return ans;
// }

//TABULATION
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int MOD = 1e9+7;
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1,0));
	
	for(int i = 0; i < n; i++)
	{
		dp[i][0] = 1;
	}

	if(arr[0] <= k)
	{
		dp[0][arr[0]] = 1;
	}

	for(int index = 1; index < n; index++)
	{
		for(int target = 0; target <= k; target++)
		{
			int not_pick = dp[index-1][target];

			int pick = 0;

			if(arr[index] <= target)
			{
				pick = dp[index - 1][target - arr[index]];
			}

			dp[index][target] = (pick + not_pick)%MOD;
		}
	}

	return dp[n-1][k];
}
/*if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
	//base case for arrays containing zeros
*/