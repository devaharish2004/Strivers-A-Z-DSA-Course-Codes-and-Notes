class Solution {
public:
    // RECURSIVE SOLUTION
    // int calc(int row, int col, vector<vector<int>>& grid)
    // {
    //     if(row == 0 && col == 0 && grid[row][col] == 0)
    //     {
    //         return 1; 
    //     }

    //     if(row < 0 || col < 0 || grid[row][col] == 1)
    //     {
    //         return 0;
    //     }

    //     int left = calc(row, col-1, grid);
    //     int right = calc(row-1, col, grid);

    //     return left+right;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     return calc(m-1, n-1, obstacleGrid);
    // }

    //MEMOIZATION
    // int calc(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&dp)
    // {
    //     if(row == 0 && col == 0 && grid[row][col] == 0)
    //     {
    //         return dp[row][col] = 1; 
    //     }

    //     if(row < 0 || col < 0 || grid[row][col] == 1)
    //     {
    //         return 0;
    //     }

    //     if(dp[row][col] != -1) return dp[row][col];

    //     int left = calc(row, col-1, grid, dp);
    //     int right = calc(row-1, col, grid, dp);

    //     return dp[row][col] = left + right;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     return calc(m-1, n-1, obstacleGrid, dp);
    // }

    //TABULATION
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     if(obstacleGrid[0][0] == 1) return 0;
    //     else dp[0][0] = 1;
    //     for(int i = 0; i < m; i++)
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             if(i == 0 && j == 0) continue;

    //             if(obstacleGrid[i][j] == 1) //if the current cell is an obstacle, mark it as 0
    //             {
    //                 dp[i][j] = 0;
    //             }

    //             else
    //             {
    //                 int left = 0;
    //                 int up = 0;
    //                 if(i > 0) //can move in the up direction
    //                 {
    //                     up = dp[i-1][j];
    //                 }

    //                 if(j > 0) //can move in the left
    //                 {
    //                     left = dp[i][j-1];
    //                 }  

    //                 dp[i][j] = left+up; 
    //             } 
    //         }   
    //     }
    //     return dp[m-1][n-1];
    // }

    //SPACE OPTIMIZATION
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> temp(n,0); //to ref the prev row

        if(obstacleGrid[0][0] == 1) return 0;
        else
        {
            temp[0] = 1;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) continue;

                if(obstacleGrid[i][j] == 1) //if the current cell is an obstacle, mark it as 0
                {
                    temp[j] = 0;
                }

                else
                {

                    if(j > 0) //can move in the left
                    {
                        int left = temp[j-1];
                        int up = temp[j];

                        temp[j] = left + up;
                    }  
                } 
            }   
        }
        return temp[n-1];
    }
};