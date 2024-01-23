public class Code {
    public int minInsertions(String s) {
        int n = s.length();
        //find n - length of longest palindromic subsequence
        //find lps
        int[][] dp = new int[n+1][n+1];
        
        for(int start = n-1; start >= 0; start--)
        {
            dp[start][start] = 1;

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

        return n - dp[0][n-1];

    }
}
