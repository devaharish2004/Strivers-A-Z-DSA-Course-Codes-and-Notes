#include <bits/stdc++.h> 
// MEMOIZATION
// int solve(int index, int weight, vector<int>&value, vector<int>&weight_arr, int n, vector<vector<int>>&dp)
// {
// 	if(index == 0)
// 	{
// 		if(weight >= weight_arr[0])  //checking the condition to pick the first box
// 		{
// 			return dp[index][weight] = value[index];
// 		}

// 		return 0;
// 	}

// 	if(dp[index][weight] != -1)
// 	{
// 		return dp[index][weight];
// 	}

// 	int not_pick = 0 + solve(index-1, weight, value, weight_arr, n, dp);

// 	int pick = INT_MIN;

// 	if(weight >= weight_arr[index]) //the bag weight must be greater than the pick box weight
// 	{
// 		pick = value[index] + solve(index-1, weight-weight_arr[index], value, weight_arr, n, dp);
// 	}

// 	return dp[index][weight] = max(pick, not_pick);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	//dp array
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
// 	return solve(n-1, maxWeight, value, weight, n, dp);
// }

//TABULATION
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	//dp array
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

// 	//base case

// 	for(int i = 0; i <= maxWeight; i++)
// 	{
// 		if(i >= weight[0])
// 		{
// 			dp[0][i] = value[0];
// 		}
// 		else
// 		{
// 			dp[0][i] = 0;
// 		}
// 	}

// 	for(int ind = 1; ind < n; ind++)
// 	{
// 		for(int w = 0; w <= maxWeight; w++)
// 		{
// 			int not_pick = dp[ind-1][w];
// 			int pick = INT_MIN;
// 			if(w >= weight[ind])
// 			{
// 				pick = value[ind] + dp[ind-1][w-weight[ind]];
// 			}
// 			dp[ind][w] = max(pick, not_pick);
// 		}
// 	}

// 	return dp[n-1][maxWeight];
// }

// SPACE OPTIMIZATION USING TWO ROWS

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
// 	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

// 	//base case

// 	for(int i = 0; i <= maxWeight; i++)
// 	{
// 		if(i >= weight[0])
// 		{
// 			prev[i] = value[0];
// 		}
// 		else
// 		{
// 			prev[i] = 0;
// 		}
// 	}

// 	for(int ind = 1; ind < n; ind++)
// 	{
// 		for(int w = 0; w <= maxWeight; w++)
// 		{
// 			int not_pick = prev[w];
// 			int pick = INT_MIN;
// 			if(w >= weight[ind])
// 			{
// 				pick = value[ind] + prev[w-weight[ind]];
// 			}
// 			curr[w] = max(pick, not_pick);
// 		}
// 		prev = curr;
// 	}

// 	return prev[maxWeight];
// }

//SPACE OPTIMIZATION USING SINGLE ROW

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	/*since the values of curr are dependent on the previous row values (index-1) and some arbitrary weight (w - weight[index]) which requires only the left half of the prev row,
	we can optimize the code further.
	We see that for any weight w, it is dependent on its previous col values and not on all the col values.
	So, we can start from the right and fill the curr values in the prev row. */

	vector<int> prev(maxWeight+1, 0);

	//base case

	for(int i = 0; i <= maxWeight; i++)
	{
		if(i >= weight[0])
		{
			prev[i] = value[0];
		}
		else
		{
			prev[i] = 0;
		}
	}

	for(int ind = 1; ind < n; ind++)
	{
		for(int w = maxWeight; w >=0; w--)
		{
			int not_pick = prev[w];
			int pick = INT_MIN;
			if(w >= weight[ind])
			{
				pick = value[ind] + prev[w-weight[ind]];
			}
			prev[w] = max(pick, not_pick);
		}
	}

	return prev[maxWeight];
}