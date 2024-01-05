#include <bits/stdc++.h> 

//MEMOIZATION

// bool solve(int index, int target, vector<int>&arr, vector<vector<int>>&dp)
// {
//     if(target == 0) return dp[index][0] = 1;

//     if(index == 0) return (dp[0][target] = arr[index] == target);

//     if(dp[index][target] != -1) return dp[index][target];

//     bool notPick = solve(index-1, target, arr, dp);
    
//     bool pick = false;

//     if(target >= arr[index])
//     {
//         pick = solve(index-1, target-arr[index], arr, dp);
//     }

//     return dp[index][target] = pick || notPick;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int>(k+1,-1));
//     return solve(n-1, k, arr, dp);
// }

//TABULATION

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<bool>> dp(n, vector<bool>(k+1, false));
//     for(int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }
//     dp[0][arr[0]] = true;
//     for(int index = 1; index < n; index++)
//     {
//         for(int target = 1; target <= k; target++)
//         {
//             bool notPick = dp[index-1][target];

//             bool pick = false;
//             if(target >= arr[index])
//             {
//                 pick = dp[index-1][target-arr[index]];
//             }
//             dp[index][target] = pick || notPick;
//         }
        
//     }

//     return dp[n-1][k];

    
// }

//SPACE OPTIMIZED
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1, false);
    prev[0] = true;
    // if(arr[0] <= k)
    prev[arr[0]] = true;
    for(int index = 1; index < n; index++)
    {
        vector<bool>curr(k+1, false);
        curr[0] = true;
        for(int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];

            bool pick = false;
            if(target >= arr[index])
            {
                pick = prev[target-arr[index]];
            }
            curr[target] = pick || notPick;
        }
        prev = curr;
    }

    return prev[k];

    
}