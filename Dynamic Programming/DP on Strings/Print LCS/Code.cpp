// MEMOIZATION
// string solve(int ind1, int ind2, string &s1, string &s2, vector<vector<string>>&dp)
// {
// 	if(ind1 == 0 || ind2 == 0)
// 	{
// 		return "";
// 	}

// 	if(dp[ind1][ind2] != "")
// 	{
// 		return dp[ind1][ind2];
// 	}

// 	if(s1[ind1-1] == s2[ind2-1])
// 	{
// 		return dp[ind1][ind2] = solve(ind1-1, ind2-1, s1, s2, dp) + s1[ind1-1];
// 	}

// 	string str1 = solve(ind1-1, ind2, s1, s2, dp);
// 	string str2 = solve(ind1, ind2-1, s1, s2, dp);

// 	if(str1.length() > str2.length())
// 	{
// 		//take s1
// 		return dp[ind1][ind2] = str1;
// 	}

// 	return dp[ind1][ind2] = str2;
// }

// string findLCS(int n, int m,string &s1, string &s2)
// {
// 	// Write your code here.
// 	vector<vector<string>> dp(n+1, vector<string>(m+1, ""));
// 	return solve(n, m, s1, s2, dp);
// }

//TABULATION
// string findLCS(int n, int m,string &s1, string &s2)
// {
// 	// Write your code here.
// 	vector<vector<string>> dp(n+1, vector<string>(m+1, ""));
// 	for(int i = 0; i < n; i++)
// 	{
// 		dp[i][0] = "";
// 	}
// 	for(int i = 0; i < m; i++)
// 	{
// 		dp[0][i] = "";
// 	}

// 	for(int ind1 = 1; ind1 <= n; ind1++)
// 	{
// 		for(int ind2 = 1; ind2 <= m; ind2++)
// 		{
// 			if(s1[ind1 - 1] == s2[ind2 - 1])
// 			{
// 				dp[ind1][ind2] = dp[ind1-1][ind2-1] + s1[ind1 - 1];
// 			}
// 			else
// 			{
// 				string str1 = dp[ind1-1][ind2];
// 				string str2 = dp[ind1][ind2 - 1];
// 				if(str1.length() > str2.length())
// 				{
// 					dp[ind1][ind2] = str1;
// 				}
// 				else
// 				{
// 					dp[ind1][ind2] = str2;
// 				}
// 			}
// 		}
// 	}

// 	return dp[n][m];
// }

//SPACE OPTIMIZATION
string findLCS(int n, int m,string &s1, string &s2)
{
	// Write your code here.
	vector<string>prev(m+1, ""), curr(m+1, "");

	for(int ind1 = 1; ind1 <= n; ind1++)
	{
		for(int ind2 = 1; ind2 <= m; ind2++)
		{
			if(s1[ind1 - 1] == s2[ind2 - 1])
			{
				curr[ind2] = prev[ind2-1] + s1[ind1 - 1];
			}
			else
			{
				string str1 = prev[ind2];
				string str2 = curr[ind2 - 1];
				if(str1.length() > str2.length())
				{
					curr[ind2] = str1;
				}
				else
				{
					curr[ind2] = str2;
				}
			}
		}
		prev = curr;
	}

	return prev[m];
}
