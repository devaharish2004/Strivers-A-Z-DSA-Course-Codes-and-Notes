
public class Code {
	//MEMOIZATION
	// public static int solve(int start, int end, String s, int[][] dp)
	// {
	// 	//base cases
	// 	if(start == end)
	// 	{
	// 		return dp[start][end] = 1;
	// 	}
	// 	if(start > end)
	// 	{
	// 		return dp[start][end] = 0;
	// 	}

	// 	if(s.charAt(start) == s.charAt(end))
	// 	{
	// 		return dp[start][end] = 2 + solve(start+1, end-1, s, dp);
	// 	}
	// 	else
	// 	{
	// 		int ans1 = solve(start+1, end, s, dp);
	// 		int ans2 = solve(start, end-1, s, dp);
	// 		return dp[start][end] = Math.max(ans1, ans2);
	// 	}
	// }

	//TABULATION
	public static int longestPalindromeSubsequence(String s) {
		// Write your code here.
		int n = s.length();
		int[][] dp = new int[n][n];
		for(int start = 0; start < n; start++)
		{
			for(int end = 0; end < n; end++)
			{
				if(start == end)
				{
					dp[start][end] = 1;
				}
			}
		}

		for(int start = n-1; start >= 0; start--)
		{
			for(int end = start+1; end < n; end++)
			{
				if(s.charAt(start) == s.charAt(end))
				{
					dp[start][end] = 2 + dp[start+1][end-1];
				}
				else
				{
					dp[start][end] = Math.max(dp[start+1][end], dp[start][end-1]);
				}
			}
		}


		return dp[0][n-1];

	}
}


//The same problem can be solved using LCS of two strings, just find the LCS(String s1, String rev(s1)) to find the longest palindromic subsequence.
//This is because for a palindrome, it must be same even when it is reversed.