class Solution {
public:
    // MEMOIZATION METHOD :
    // int findMinPath(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&dp)
    // {
    //     if(row < 0 || col < 0)
    //     {
    //         return INT_MAX;
    //     }
    //     if(row == 0 && col == 0)
    //     {
    //         return dp[row][col] = grid[row][col];
    //     }
    //     if(dp[row][col] != -1)
    //     {
    //         return dp[row][col];
    //     }
        
    //     int left = findMinPath(row-1, col, grid,dp);
    //     int right = findMinPath(row, col-1, grid,dp);

    //     int mini = min(left, right);

    //     return dp[row][col] = grid[row][col] + mini;

    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>> dp(m, vector<int>(n,-1));

    //     int ans = findMinPath(m-1,n-1,grid,dp);
    //     return ans;
    // }

    //TABULATION METHOD :

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != 0 || j != 0) //if it is not the starting cell
                {
                    int left = INT_MAX;
                    int right = INT_MAX;
                    if(i-1 >= 0) //check for the prev row
                    {
                        left = dp[i-1][j];
                    }
                    if(j-1 >= 0) //check for the prev col
                    {
                        right = dp[i][j-1];
                    }
                    dp[i][j] = grid[i][j] + min(left, right);
                }
            }
        }

        return dp[m-1][n-1];
    }
    }
};