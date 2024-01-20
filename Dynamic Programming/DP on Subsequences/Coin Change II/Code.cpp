//class Solution {
//public:
    //MEMOIZATION
    // int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp)
    // {
    //     if(amount == 0)
    //     {
    //         return 1;
    //     }

    //     if(ind == 0)
    //     {
    //         if(amount%coins[ind] == 0) return 1;
    //         return 0;
    //     }

    //     if(dp[ind][amount] != -1)
    //     {
    //         return dp[ind][amount];
    //     }

    //     int pick = 0;
    //     if(amount >= coins[ind])
    //     {
    //         pick = solve(ind, amount - coins[ind], coins, dp);
    //     }

    //     int notPick = solve(ind-1, amount, coins, dp);

    //     return dp[ind][amount] = pick + notPick;
    // }
    // int change(int amount, vector<int>& coins) 
    // {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1,-1));
    //     return solve(n-1, amount, coins, dp);
    // }

    //TABULATION
    // int change(int amount, vector<int>& coins) 
    // {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n
    //     for(int i = 0; i < n; i++)
    //     {
    //         if(amount == 0) dp[i][0] = 1;
    //     }

    //     for(int i = 0; i <= amount; i++)
    //     {
    //         if(i % coins[0] == 0)
    //         {
    //             dp[0][i] = 1;
    //         }
    //     }

    //     for(int ind = 1; ind < n; ind++)
    //     {
    //         for(int amt = 0; amt <= amount; amt++)
    //         {
    //             int notPick = dp[ind-1][amt];
    //             int pick = 0;
    //             if(amt >= coins[ind])
    //             {
    //                 pick = dp[ind][amt-coins[ind]];
    //             }

    //             dp[ind][amt] = pick + notPick;
    //         }
    //     }

    //     return dp[n-1][amount];
    // }
//}

//SPACE OPTIMIZED
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}

int main() {
    vector<int> arr = {1, 2, 3};  // Coin denominations
    int target = 4;  // Target sum
    int n = arr.size();  // Number of coin denominations

    // Call the function to calculate and output the total number of ways to make change
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0;  // Return 0 to indicate successful program execution
}
