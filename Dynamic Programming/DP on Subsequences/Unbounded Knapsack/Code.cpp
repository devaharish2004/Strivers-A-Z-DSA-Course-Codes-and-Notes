#include <bits/stdc++.h>

// int solve(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp)
// {

//     if(ind == 0)
//     {
//         return (w / weight[0]) * profit[0];
//     }

//     if(dp[ind][w] != -1) return dp[ind][w];

//     int notTake = 0 + solve(ind-1, w, profit, weight, dp);

//     int take = INT_MIN; //since the max profit to be found

//     if(w >= weight[ind])
//     {
//         take = profit[ind] + solve(ind, w - weight[ind], profit, weight, dp);
//     }

//     return dp[ind][w] = max(take, notTake);
// }

//TABULATION
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     // Write Your Code Here.
//     vector<vector<int>>dp(n, vector<int>(w+1, 0));
//     for(int wt = 0; wt <= w; wt++)
//     {
//         dp[0][wt] = (wt/weight[0])*profit[0];
//     }

//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int wt = 0; wt <= w; wt++)
//         {
//             int notTake = dp[ind-1][wt];
//             int take = INT_MIN;
//             if(wt >= weight[ind])
//             {
//                 take = profit[ind] + dp[ind][wt - weight[ind]];
//             }
//             dp[ind][wt] = max(take, notTake);
//         }
        
//     }

//     return dp[n-1][w];
// }

//SPACE OPTIMIZATION USING TWO VECTORS
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     // Write Your Code Here.
//     vector<int> prev(w+1, 0), curr(w+1, 0);
//     for(int wt = 0; wt <= w; wt++)
//     {
//         prev[wt] = (wt/weight[0])*profit[0];
//     }

//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int wt = 0; wt <= w; wt++)
//         {
//             int notTake = prev[wt];
//             int take = INT_MIN;
//             if(wt >= weight[ind])
//             {
//                 take = profit[ind] + curr[wt - weight[ind]];
//             }
//             curr[wt] = max(take, notTake);
//         }

//         prev = curr;
        
//     }

//     return prev[w];
// }

//SPACE OPTIMIZATION USING TWO ROWS
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     // Write Your Code Here.
//     vector<int> prev(w+1, 0), curr(w+1, 0);
//     for(int wt = 0; wt <= w; wt++)
//     {
//         prev[wt] = (wt/weight[0])*profit[0];
//     }

//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int wt = 0; wt <= w; wt++)
//         {
//             int notTake = prev[wt];
//             int take = INT_MIN;
//             if(wt >= weight[ind])
//             {
//                 take = profit[ind] + curr[wt - weight[ind]];
//             }
//             curr[wt] = max(take, notTake);
//         }

//         prev = curr;
        
//     }

//     return prev[w];
// }

//SPACE OPTIMIZATION USING ONE ROW

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(w+1, 0);
    for(int wt = 0; wt <= w; wt++)
    {
        prev[wt] = (wt/weight[0])*profit[0];
    }

    for(int ind = 1; ind < n; ind++)
    {
        for(int wt = 0; wt <= w; wt++)
        {
            int notTake = prev[wt];
            int take = INT_MIN;
            if(wt >= weight[ind])
            {
                take = profit[ind] + prev[wt - weight[ind]];
            }
            prev[wt] = max(take, notTake);
        }
        
    }

    return prev[w];
}