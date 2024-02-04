public class Solution 
{
    //MEMOIZATION
    // public static int solve(int ind, int buy, int[] prices, int n , int fee, int[][] dp)
    // {
    //     if(ind >= n) return 0;

    //     if(dp[ind][buy] != -1)
    //     {
    //         return dp[ind][buy];
    //     }

    //     if(buy == 0)
    //     {
    //         int buyStock = -prices[ind] + solve(ind+1, 1, prices, n, fee, dp);
    //         int notBuyStock = 0 + solve(ind+1, 0, prices, n, fee, dp);
    //         return dp[ind][buy] = Math.max(buyStock, notBuyStock);
    //     }
    //     else
    //     {
    //         int sellStock = prices[ind] - fee + solve(ind+1, 0, prices, n, fee, dp);
    //         int notSellStock = 0 + solve(ind+1, 1, prices, n, fee, dp);
    //         return dp[ind][buy] = Math.max(sellStock, notSellStock);
    //     }
    // }
    // public static int maximumProfit(int[] prices, int n, int fee) 
    // {
    //     // Write your code here.
    //     if(n == 0) return 0;
    //     int[][] dp = new int[n][2];
    //     for(int[] row : dp)
    //     {
    //         Arrays.fill(row, -1);
    //     }
    //     return solve(0, 0, prices, n, fee, dp);
    // }

    //TABULATION
    // public static int maximumProfit(int[] prices, int n, int fee) 
    // {
    //     // Write your code here.
    //     if(n == 0) return 0;
    //     int[][] dp = new int[n+1][2];
        
    //     for(int ind = n-1; ind >= 0; ind--)
    //     {
    //         dp[ind][0] = Math.max(-prices[ind] + dp[ind+1][1], dp[ind+1][0]);
    //         dp[ind][1] = Math.max(prices[ind] - fee + dp[ind+1][0], dp[ind+1][1]);
    //     }

    //     return dp[0][0];
    // }

    //SPACE OPTIMIZATION
    public static int maximumProfit(int[] prices, int n, int fee) 
    {
        // Write your code here.
        if(n == 0) return 0;
        int[] front = new int[2];
        int[] curr = new int[2];
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            curr[0] = Math.max(-prices[ind] + front[1], front[0]);
            curr[1] = Math.max(prices[ind] - fee + front[0], front[1]);

            System.arraycopy(curr, 0, front, 0, 2);
        }

        return curr[0];
    }
}