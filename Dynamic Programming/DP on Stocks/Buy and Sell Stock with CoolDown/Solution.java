import java.util.*;
public class Solution {

    // public static int solve(int day, int buy, int[] prices, int n, int[][] dp)
    // {
    //     //base cases
    //     if(day >= n)
    //     {
    //         return 0;
    //     }

    //     if(dp[day][buy] != -1)
    //     {
    //         return dp[day][buy];
    //     }

    //     if(buy == 0) //you can buy the stock
    //     {
    //         int buyStock = -prices[day] + solve(day+1, 1, prices, n, dp);
    //         int notBuyStock = 0 + solve(day+1, 0, prices, n, dp);
    //         return dp[day][buy] = Math.max(buyStock, notBuyStock);
    //     }
    //     else
    //     {
    //         //if we are selling, go to day + 2 
    //         int sellStock = prices[day] + solve(day+2, 0, prices, n, dp);
    //         int notSellStock = 0 + solve(day+1, 1, prices, n, dp);
    //         return dp[day][buy] = Math.max(sellStock, notSellStock);
    //     }
    // }
    // public static int stockProfit(int[] prices) {
    //     // Write your code here.
    //     int n = prices.length;
    //     int[][] dp = new int[n][2];
    //     for(int[] row : dp)
    //     {
    //         Arrays.fill(row, -1);
    //     }
    //     return solve(0, 0, prices, n, dp);
    // }

    //TABULATION
    // public static int stockProfit(int[] prices) {
    //     // Write your code here.
    //     int n = prices.length;
    //     int[][] dp = new int[n+2][2];
        
    //     //base case for clear explanation
    //     //declare dp[n][buy] && dp[n+1][buy] == 0
    //     for(int i = n; i < n+2; i++)
    //     {
    //         for(int buy = 0; buy < 2; buy++)
    //         {
    //             dp[i][buy] = 0;
    //         }
    //     }

    //     for(int day = n-1; day >= 0; day--)
    //     {
    //         for(int buy = 0; buy < 2; buy++)
    //         {
    //             if(buy == 0)
    //             {
    //                 dp[day][buy] = Math.max(-prices[day] + dp[day+1][1], dp[day+1][0]);
    //             }
    //             else
    //             {
    //                 dp[day][buy] = Math.max(prices[day] + dp[day+2][0], dp[day+1][1]);
    //             }
    //         }
    //     }

    //     return dp[0][0];
        
    // }

    //space optimization - we need two rows only for calculating each row
    public static int stockProfit(int[] prices) {
        // Write your code here.
        int n = prices.length;
        int[] front1 = new int[2];
        int[] front2 = new int[2];
        int[] curr = new int[2];

        for(int day = n-1; day >= 0; day--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                if(buy == 0)
                {
                    curr[buy] = Math.max(-prices[day] + front1[1], front1[0]);
                }
                else
                {
                    curr[buy] = Math.max(prices[day] + front2[0], front1[1]);
                }
            }

            front2 = front1.clone();
            front1 = curr.clone();
        }

        return front1[0];
        
    }
}
