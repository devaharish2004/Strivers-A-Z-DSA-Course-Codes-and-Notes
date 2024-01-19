#include <bits/stdc++.h> 

//MEMOIZATION
// int solve(int ind, int target, vector<int>& arr, vector<vector<int>>&dp)
// {
//     //base case
//     if(ind == 0)
//     {
//         if(target == 0 && arr[ind] == 0) return dp[ind][target] = 2;
//         if(target == 0 || target == arr[ind]) return dp[ind][target] = 1;
//         return dp[ind][target] = 0;
//     }

//     if(dp[ind][target] != -1)
//     {
//         return dp[ind][target];
//     }

//     int not_pick = solve(ind-1, target, arr, dp);

//     int pick = 0;

//     if(target >= arr[ind])
//     {
//         pick = solve(ind-1, target - arr[ind], arr, dp);
//     }

//     return dp[ind][target] = pick + not_pick;

// }

// int targetSum(int n, int target, vector<int>& arr) 
// {
//     // Write your code here.
//     int sum = 0;
//     for(int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     //edge cases
//     if(sum - target < 0)
//     {
//         return 0;
//     }

//     if ((sum - target) % 2 == 1) 
//     {
//         return 0;
//     }

//     int val = (sum - target)/2;

//     vector<vector<int>> dp(n, vector<int>(val+1, -1));

//     return solve(n-1, val, arr, dp);
    
// }

//TABULATION
// int targetSum(int n, int target, vector<int>& arr) 
// {
//     // Write your code here.
//     int sum = 0;
//     for(int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     //edge cases
//     if(sum - target < 0)
//     {
//         return 0;
//     }

//     if ((sum - target) % 2 == 1) 
//     {
//         return 0;
//     }

//     int val = (sum - target)/2;

//     vector<vector<int>> dp(n, vector<int>(val+1, 0));

//     //base cases
//     if(arr[0] == 0)
//     {
//         dp[0][0] = 2;
//     }
//     else
//     {
//         dp[0][0] = 1;
//         if(arr[0] <= val)
//         dp[0][arr[0]] = 1;
//     }

//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int target = 0; target <= val; target++)
//         {
//             int notTaken = dp[ind-1][target];
//             int taken = 0;
//             if(target >= arr[ind])
//             {
//                 taken = dp[ind-1][target - arr[ind]];
//             }

//             dp[ind][target] = taken + notTaken;
//         }
//     }

//     return dp[n-1][val]; 
// }

//SPACE OPTIMIZATION

int targetSum(int n, int target, vector<int>& arr) 
{
    // Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    //edge cases
    if(sum - target < 0)
    {
        return 0;
    }

    if ((sum - target) % 2 == 1) 
    {
        return 0;
    }

    int val = (sum - target)/2;

    vector<int> prev(val+1, 0);

    //base cases
    if(arr[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
        if(arr[0] <= val)
        prev[arr[0]] = 1;
    }

    for(int ind = 1; ind < n; ind++)
    {
        vector<int> curr(val+1, 0);

        for(int target = 0; target <= val; target++)
        {
            int notTaken = prev[target];
            int taken = 0;
            if(target >= arr[ind])
            {
                taken = prev[target - arr[ind]];
            }

            curr[target] = taken + notTaken;
        }

        prev = curr;
    }

    return prev[val]; 
}
