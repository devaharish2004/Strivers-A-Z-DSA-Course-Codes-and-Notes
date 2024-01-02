class Solution {
public:
    //MEMOIZATION
    // int solve(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp)
    // {
    //     if(row == n-1)
    //     {
    //         return dp[row][col] = triangle[row][col];
    //     }

    //     if(dp[row][col] != -1)
    //     {
    //         return dp[row][col];
    //     }
    //     //go to index i on the next row
    //     int curr = solve(row+1, col, triangle, n, dp);
    //     //go to index i+1 on the next row
    //     int next = solve(row+1, col+1, triangle, n, dp);

    //     return dp[row][col] = triangle[row][col] + min(curr,next);

    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     //find the size of the triangle
    //     int n = INT_MIN;
    //     for(auto it : triangle)
    //     {
    //         int x = it.size();
    //         n = max(x,n);
    //     }
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return solve(0,0,triangle, n, dp);
    // }

    //TABULATION
    int minimumTotal(vector<vector<int>>& triangle) {
        //find the size of the triangle
        int n = INT_MIN;
        for(auto it : triangle)
        {
            int x = it.size();
            n = max(x,n);
        }
        vector<int> row(n, 0);
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(i == n-1)
                {
                    row[j] = triangle[i][j];
                }
                else
                {
                    int val = min(row[j], row[j+1]);
                    row[j] = triangle[i][j] + val;
                }
            }
        }

        return row[0];
    }
};