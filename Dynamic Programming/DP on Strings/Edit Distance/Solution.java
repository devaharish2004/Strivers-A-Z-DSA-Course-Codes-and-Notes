class Solution {
    
    //minimum number of operations required to convert word1[0...ind1] to word2[0...ind2]
    // public int solve(int ind1, int ind2, String word1, String word2, int[][] dp)
    // {
    //     if(ind1 < 0) return ind2 + 1;  //if word1 is exhausted, "" -> word2 requires ind2+1 operations
    //     if(ind2 < 0) return ind1 + 1;  //similar to the above comment

    //     if(dp[ind1][ind2] != -1)
    //     {
    //         return dp[ind1][ind2];
    //     }

    //     if(word1.charAt(ind1) == word2.charAt(ind2))
    //     {
    //         return dp[ind1][ind2] = 0 + solve(ind1-1, ind2-1, word1, word2, dp); //no operations are required
    //     }

    //     int insert = 1 + solve(ind1, ind2 - 1, word1, word2, dp);
    //     int delete = 1 + solve(ind1 - 1, ind2, word1, word2, dp);
    //     int replace = 1 + solve(ind1 - 1, ind2 - 1, word1 , word2, dp);

    //     return dp[ind1][ind2] = Math.min(insert, Math.min(delete, replace));
    // }

    // public int minDistance(String word1, String word2) {
    //     int n = word1.length();
    //     int m = word2.length();
    //     int[][] dp = new int[n][m];
    //     for(int[] row : dp)
    //     {
    //         Arrays.fill(row, -1);
    //     }
    //     return solve(n-1, m-1, word1, word2, dp);
    // }

    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int[][] dp = new int[n+1][m+1];
        //index shifting
        for(int ind1 = 0; ind1 <= n; ind1++)
        {
            dp[ind1][0] = ind1; 
        }
        for(int ind2 = 0; ind2 <= m; ind2++)
        {
            dp[0][ind2] = ind2;
        }

        for(int ind1 = 1; ind1 <= n; ind1++)
        {
            for(int ind2 = 1; ind2 <= m; ind2++)
            {
                if(word1.charAt(ind1 - 1) == word2.charAt(ind2 - 1))
                {
                    dp[ind1][ind2] = 0 + dp[ind1-1][ind2-1];
                }
                else
                {
                    int insert = dp[ind1][ind2-1];
                    int delete = dp[ind1 - 1][ind2];
                    int replace = dp[ind1 - 1][ind2 - 1];
                
                    dp[ind1][ind2] = 1 + Math.min(insert, Math.min(delete, replace));

                }
                
            }
        }

        return dp[n][m];


    }
}