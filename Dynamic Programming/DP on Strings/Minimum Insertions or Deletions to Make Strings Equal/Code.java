public class Code {
    public static int canYouMake(String s1, String s2) {
        // Write your code here.
        int n = s1.length();
        int m = s2.length();
        //find the lcs
        int[][] dp = new int[n+1][m+1];

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1.charAt(i-1) == s2.charAt(j-1))
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } 
                else
                {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int ans = (n - dp[n][m]) + (m - dp[n][m]);

        return ans;
    }
}

//find out the longest common subsequence, since these are the portions that you won't insert/delete as they are already there.
//figure out the remaining number of letters, and that's what the answer is.