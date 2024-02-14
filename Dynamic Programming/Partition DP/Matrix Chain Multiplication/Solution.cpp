/*
 * PARTITION DP IS SPLITTING A GIVEN ARRAY INTO PARTS AND FINDING SOLUTION FOR EACH TO FIND THE ANSWER.
 * STEPS FOR SOLVING A SUM USING PARTITION DP :
 * 1. START WITH A ENTIRE BLOCK / ARRAY
 * 2. TRY ALL PARTITIONS
 * 3. RETURN THE BEST POSSIBLE TWO PARTITIONS
 */

#include <bits/stdc++.h>

// MEMOIZATION

// int solve(int start, int end, int* arr, vector<vector<int>>&dp)
// {
//     if(start == end) return 0;

//     if(dp[start][end] != -1)
//     {
//         return dp[start][end];
//     }

//     int ans = (int)1e9;

//     for(int part = start; part < end; part++)
//     {
//         int val = (arr[start-1] * arr[part] * arr[end]) + solve(start, part, arr, dp) + solve(part+1, end, arr, dp);
//         ans = min(ans, val);
//     }

//     return dp[start][end] = ans;
// }


// int matrixChainMultiplication(int* arr, int n) {
//     // Write your code here
//     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));


//     return solve(1, n, arr, dp);
// }

//TABULATION

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    //base case
    for(int i = 0; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for(int i = n-1; i >= 1; i--)
    {
        for(int j = i+1; j <= n; j++)
        {
            int ans = (int)1e9;

            for(int k = i; k < j; k++)
            {
                int val = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                ans = min(ans, val);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n];

}

