#include <bits/stdc++.h> 

//MEMOIZATION IS ENOUGH FOR 3D DP, TABULATION AND SPACE OPTIMIZATION CAN ALSO BE DONE IN THIS.
int solve(int row, int col_Alice, int col_Bob, vector<vector<int>>&grid, int r, int c, vector<vector<vector<int>>>& dp)
{
    if(col_Alice < 0 || col_Alice >= c || col_Bob < 0 || col_Bob >=c)
    {
        return -1e8; // not returning INT_MIN as when added to another negative number will result in out of bounds
    }

    if(row == r-1) //reaching the last row
    {
        if(col_Alice == col_Bob) //both of them are at the same cell
        {
            return grid[row][col_Alice];
        }
        else
        {
            return grid[row][col_Alice] + grid[row][col_Bob];
        }
    }

    if(dp[row][col_Alice][col_Bob] != -1)
    {
        return dp[row][col_Alice][col_Bob];
    }

    //exploring all paths
    int m = -1e8;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int val = 0;
            if(col_Alice == col_Bob)
            {
                val = grid[row][col_Alice];
            }
            else
            {
                val = grid[row][col_Alice] + grid[row][col_Bob];
            }

            val += solve(row + 1, col_Alice + i, col_Bob + j, grid, r, c, dp);

            m = max(m, val);
        }
    }

    return dp[row][col_Alice][col_Bob] = m;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0,0,c-1,grid,r,c, dp);

}