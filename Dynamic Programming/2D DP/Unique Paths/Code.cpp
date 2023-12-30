class Solution {
public:
    // MEMOIZATION 
    // int calc(int row, int col, vector<vector<int>> & dp)
    // {
    //     if(row == 0 && col == 0)
    //     {
    //         return dp[row][col] = 1; //1 path to reach (0,0)
    //     }

    //     if(row < 0 || col < 0) 
    //     {
    //         return 0; //out of bounds - no path exists
    //     }

    //     if(dp[row][col] != -1)
    //     {
    //         return dp[row][col];
    //     }


    //     int left = calc(row, col-1, dp);
    //     int up = calc(row-1, col, dp);

    //     return dp[row][col] = left + up;
    // }
    // int uniquePaths(int m, int n) 
    // {
    //     //2-D DP
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     return calc(m-1, n-1, dp);
    // }

    //TABULATION
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) continue;
                //check if going left and up is valid
                int left = 0;
                int up = 0;
                if(i > 0) //up
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
};