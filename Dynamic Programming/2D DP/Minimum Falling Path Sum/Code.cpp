class Solution {
public:
    //MEMOIZATION
    // int solve(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>&dp)
    // {
    //     if(col < 0 || col >= n)
    //     {
    //         return INT_MAX;
    //     }

    //     if(dp[row][col] != -1)
    //     {
    //         return dp[row][col];
    //     }

    //     if(row == 0)
    //     {
    //         return dp[row][col] = matrix[row][col];
    //     }

    //     //three ways of recursion
    //     int left_diagonal = solve(row-1, col-1, matrix, n, dp);
    //     int up = solve(row-1, col, matrix, n, dp);
    //     int right_diagonal = solve(row-1, col+1, matrix, n, dp);

    //     int val = min(left_diagonal, min(up, right_diagonal));

    //     return dp[row][col] = matrix[row][col] + val;
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n,-1));
    //     int m = INT_MAX;
    //     for(int i = 0; i < n; i++)
    //     {   
    //         m = min(m, solve(n-1, i, matrix, n, dp));
    //     }   
    //     return m;
    // }

    //TABULATION
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n,-1));
    //     //base case
    //     for(int i = 0; i < n; i++)
    //     {
    //         dp[0][i] = matrix[0][i];
    //     }

    //     for(int i = 1; i < n; i++)
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             int left_diagonal = INT_MAX;
    //             int right_diagonal = INT_MAX;
    //             int up = dp[i-1][j];
    //             if(j > 0)
    //             {
    //                 left_diagonal = dp[i-1][j-1];
    //             }
    //             if(j < n-1)
    //             {
    //                 right_diagonal = dp[i-1][j+1];
    //             }
    //             dp[i][j] = matrix[i][j] + min(left_diagonal, min(right_diagonal, up));
    //         }
    //     }

    //     int m = INT_MAX;
    //     for(int i = 0; i < n; i++)
    //     {
    //         m = min(m, dp[n-1][i]);
    //     }
    //     return m;
    // }

    //SPACE OPTIMIZED SOLUTION
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> temp(n);
        //base case
        for(int i = 0; i < n; i++)
        {
            temp[i] = matrix[0][i];
        }

        for(int i = 1; i < n; i++)
        {
            vector<int> curr(n);

            for(int j = 0; j < n; j++)
            {
                int left_diagonal = INT_MAX;
                int right_diagonal = INT_MAX;
                int up = temp[j];
                if(j > 0)
                {
                    left_diagonal = temp[j-1];
                }
                if(j < n-1)
                {
                    right_diagonal = temp[j+1];
                }
                curr[j] = matrix[i][j] + min(left_diagonal, min(right_diagonal, up));
            }

            temp = curr;
        }

        int m = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            m = min(m, temp[i]);
        }
        return m;
    }
};