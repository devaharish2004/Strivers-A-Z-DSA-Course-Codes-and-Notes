class Solution 
{
    // MEMOIZATION
    // static int solve(int index, int amount, int[] coins, int[][] dp)
    // {
    //     if(index == 0)
    //     {
    //         if(amount == 0) return dp[index][amount] = 0;

    //         if(amount % coins[0] == 0) //if amount is divisible by coins[0]
    //         {
    //             return dp[index][amount] = amount/coins[0];
    //         }

    //         return dp[index][amount] = (int)Math.pow(10, 9);
    //     }

    //     if(dp[index][amount] != -1)
    //     {
    //         return dp[index][amount];
    //     }

    //     int not_pick = solve(index-1, amount, coins, dp);

    //     int pick = (int)Math.pow(10, 9);

    //     if(amount >= coins[index])
    //     {
    //         pick = 1 + solve(index, amount - coins[index], coins, dp);
    //     }

    //     return dp[index][amount] = Math.min(pick, not_pick);
    // }

    // public int coinChange(int[] coins, int amount) 
    // {
    //     int n = coins.length;
    //     int[][] dp = new int[n][amount+1];
    //     for(int[] rows : dp)
    //     {
    //         Arrays.fill(rows, -1);
    //     }
    //     int ans = solve(n-1, amount, coins, dp);
    //     if(ans >= (int)Math.pow(10,9))
    //     {
    //         return -1;
    //     }
    //     return ans;
    // }

    //TABULATION
    // public int coinChange(int[] coins, int amount) 
    // {
    //     int n = coins.length;
    //     int[][] dp = new int[n][amount+1];
    //     for(int[] rows : dp)
    //     {
    //         Arrays.fill(rows, (int)Math.pow(10, 9));
    //     }

    //     //base case
    //     for(int amt = 0; amt <= amount; amt++)
    //     {
    //         if(amt == 0) dp[0][amt] = 0;
    //         if(amt%coins[0] == 0)
    //         {
    //             dp[0][amt] = amt/coins[0];
    //         }
    //     }

    //     for(int ind = 1; ind < n; ind++)
    //     {
    //         for(int amt = 0; amt <= amount; amt++)
    //         {
    //             int not_pick = dp[ind-1][amt];
    //             int pick = (int)Math.pow(10,9);
    //             if(amt >= coins[ind])
    //             {
    //                 pick = 1 + dp[ind][amt-coins[ind]];
    //             }
    //             dp[ind][amt] = Math.min(pick, not_pick);
    //         }
    //     }

    //     if(dp[n-1][amount] >= (int)Math.pow(10,9))
    //     {
    //         return -1;
    //     }

    //     return dp[n-1][amount];
    // }

    //SPACE OPTIMIZATION - can be optimized further to use only one array as in Knapsack problem
    public int coinChange(int[] coins, int amount) 
    {
        int n = coins.length;
        int[] prev = new int[amount+1];
        int[] curr = new int[amount + 1];

        //base case
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0)
            {
                prev[amt] = amt/coins[0];
            }
            else
            {
                prev[amt] = (int)Math.pow(10,9);
            }
        }

        for(int ind = 1; ind < n; ind++)
        {
            for(int amt = 0; amt <= amount; amt++)
            {
                int notPick = prev[amt];
                int pick = (int)Math.pow(10,9);
                if(amt >= coins[ind])
                {
                    pick = 1 + curr[amt - coins[ind]];
                }
                curr[amt] = Math.min(pick, notPick);
            }
            prev = curr;
        }

        return (prev[amount] >= (int)Math.pow(10,9)) ? -1 : prev[amount];
    }
}