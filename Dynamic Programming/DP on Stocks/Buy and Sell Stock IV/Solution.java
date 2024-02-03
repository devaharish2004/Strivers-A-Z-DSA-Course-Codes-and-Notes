class Solution 
{
    //MEMOIZATION
    // int solve (int ind, int buy, int trans, int n, int k, int[] prices, int[][][] dp)
    // {
    //     //base cases
    //     if(ind >= n || trans >= k)
    //     {
    //         return 0;
    //     }

    //     if(dp[ind][buy][trans] != -1)
    //     {
    //         return dp[ind][buy][trans];
    //     }
        
    //     if(buy == 0) //you have to buy a new stock
    //     {
    //         int buyStock = -prices[ind] + solve(ind+1, 1, trans, n, k, prices, dp);
    //         int notBuyStock = 0 + solve(ind+1, 0, trans, n, k, prices, dp);
    //         return dp[ind][buy][trans] = Math.max(buyStock, notBuyStock);
    //     }
    //     else // you have to sell the stock
    //     {
    //         int sellStock = prices[ind] + solve(ind+1, 0, trans+1, n, k, prices, dp);
    //         int notSellStock = 0 + solve(ind+1, 1, trans, n, k, prices, dp);
    //         return dp[ind][buy][trans] = Math.max(sellStock, notSellStock);
    //     }
    // }

    // public int maxProfit(int k, int[] prices) 
    // {
    //     int n = prices.length;
    //     int[][][] dp = new int[n][2][k];
    //     for(int[][] cols : dp)
    //     {
    //         for(int[] row : cols)
    //         {
    //             Arrays.fill(row, -1);
    //         }
    //     }
    //     return solve(0, 0, 0, n, k, prices, dp);
    // }

    //TABULATION
    // public int maxProfit(int k, int[] prices) 
    // {
    //     int n = prices.length;
    //     //when initializing the dp table, the base cases are taken care of
    //     int[][][] dp = new int[n+1][2][k+1];

    //     for(int ind = n-1; ind >= 0; ind--)
    //     {
    //         for(int buy = 0; buy <= 1; buy++)
    //         {
    //             for(int trans = k-1; trans >= 0; trans--)
    //             {
    //                 if(buy == 0) // need to buy a stock
    //                 {
    //                     dp[ind][buy][trans] = Math.max(-prices[ind] + dp[ind+1][1][trans], dp[ind+1][0][trans]);
    //                 }
    //                 else
    //                 {
    //                     dp[ind][buy][trans] = Math.max(prices[ind] + dp[ind+1][0][trans+1], dp[ind+1][1][trans]);
    //                 }
    //             }
    //         }
    //     }
        
    //     return dp[0][0][0];
        
    // }
    //SPACE OPTIMIZATION
    public int maxProfit(int k, int[] prices) 
    {
        int n = prices.length;
        //when initializing the dp table, the base cases are taken care of
        int[][] after = new int[2][k+1];
        int[][] curr = new int[2][k+1];

        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int trans = k-1; trans >= 0; trans--)
                {
                    if(buy == 0) // need to buy a stock
                    {
                        curr[buy][trans] = Math.max(-prices[ind] + after[1][trans], after[0][trans]);
                    }
                    else
                    {
                        curr[buy][trans] = Math.max(prices[ind] + after[0][trans+1], after[1][trans]);
                    }
                }
            }

            after = curr.clone();
        }
        
        return curr[0][0];
        
    }
}

//DO IT AS SAME AS PREVIOUS PROBLEM, there we did atmost 2 transactions, here we are doing atmost k transactions
