//MEMOIZATION
// int solve(int start, int end, vector<int>&arr, vector<vector<int>>& dp)
// {
//     if(start > end) return 0;

//     if(dp[start][end] != -1) return dp[start][end];

//     int maxi = INT_MIN;
//     for(int ind = start; ind <= end; ind++)
//     {
//         int cost = arr[start-1] * arr[ind] * arr[end+1] + 
//                    solve(start, ind-1, arr, dp) + 
//                    solve(ind+1, end, arr, dp);

//         maxi = max(cost, maxi);
//     }

//     return dp[start][end] = maxi;
// }


// int burstBalloons(vector<int> &arr){
//     // Write your code here.
//     int n = arr.size();
//     arr.push_back(1);
//     arr.insert(arr.begin(), 1);
//     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//     return solve(1, n, arr, dp);
    
// }

//TABULATION
#include <vector>
#include <limits.h>
using namespace std;

int burstBalloons(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));    //at end == n, it will search for index n+1 in dp array. That is why we give n+2 as the size

    //base case
    for(int start = 1; start <= n; start++)
    {
        for(int end = 1; end <= n; end++)
        {
            if(start > end)
            {
                dp[start][end] = 0;
            }
        }
    }

    for(int start = n; start >= 1; start--)
    {
        for(int end = 1; end <= n; end++)
        {
            if(start > end) continue;
            int maxi = INT_MIN;
            for(int ind = start; ind <= end; ind++)
            {
                int cost = arr[start-1] * arr[ind] * arr[end+1] + 
                           dp[start][ind-1]+ 
                           dp[ind+1][end];

                maxi = max(maxi, cost);
            }

            dp[start][end] = maxi;
        }
    }

    return dp[1][n];
    
}