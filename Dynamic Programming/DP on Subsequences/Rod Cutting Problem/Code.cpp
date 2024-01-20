// MEMOIZATION
// int solve(int ind, int rodSize, vector<int>&price, vector<vector<int>> & dp)
// {
// 	if(ind == 1)
// 	{
// 		return rodSize * price[0];
// 	}

// 	if(dp[ind][rodSize] != -1)
// 	{
// 		return dp[ind][rodSize];
// 	}

// 	int notCut = solve(ind-1, rodSize, price, dp);//not cutting at ind size

// 	int cut = INT_MIN;

// 	if(rodSize >= ind)
// 	{
// 		cut = price[ind-1] + solve(ind, rodSize - ind, price, dp);
// 	}

// 	return dp[ind][rodSize] = max(cut, notCut);
// }

// int cutRod(vector<int> &price, int n)
// {
// 	// Write your code here.
// 	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
// 	return solve(n, n, price, dp);
// }

//TABULATION
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	
	for(int rodSize = 0; rodSize <= n; rodSize++)
	{
		dp[1][rodSize] = rodSize * price[0];
	}

	for(int ind = 2; ind <= n; ind++)
	{
		for(int rodSize = 1; rodSize <= n; rodSize++)
		{
			int notCut = dp[ind-1][rodSize];
			int cut = INT_MIN;
			if(rodSize >= ind)
			{
				cut = price[ind-1] + dp[ind][rodSize - ind];
			}

			dp[ind][rodSize] = max(cut, notCut);
		}
	}

	return dp[n][n];

}

