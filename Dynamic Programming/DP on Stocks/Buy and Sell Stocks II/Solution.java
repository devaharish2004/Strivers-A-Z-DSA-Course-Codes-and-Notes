import java.util.Arrays;

public class Solution 
{
    //MEMOIZATION
    // public static long solve(int ind, int buy, int n, long[] values, long[][] dp)
    // {
    //     //base case
    //     if(ind >= n) return 0;

    //     if(dp[ind][buy] != -1)
    //     {
    //         return dp[ind][buy];
    //     }

    //     if(buy == 0)  //means that we didn't buy any previous stocks
    //     {
    //         //two options - buy this stock or don't buy this stock
    //         long buyStock = solve(ind+1, 1, n, values, dp) - values[ind];
    //         long notBuyStock = solve(ind+1, 0, n, values, dp);

    //         return dp[ind][buy] = Math.max(buyStock, notBuyStock);
    //     }
    //     //otherwise we bought a stock earlier, we have to sell it
    //     long sellStock = values[ind] + solve(ind+1, 0, n, values, dp);
    //     long notSellStock = solve(ind+1, 1, n, values, dp);

    //     return dp[ind][buy] = Math.max(sellStock, notSellStock);
    // }

    // public static long getMaximumProfit (int n, long[] values) 
    // {
    //     // Your code goes here.
    //     long[][] dp = new long[n][2];
    //     for(long[] row : dp)
    //     {
    //         Arrays.fill(row, -1);
    //     }
    //     return solve(0, 0, n, values, dp);
    // }

    //TABULATION
    // public static long getMaximumProfit (int n, long[] values) 
    // {
        
    //     //base case
    //     long[][] dp = new long[n+1][2];

    //     dp[n][0] = 0;
    //     dp[n][1] = 0;

    //     for(int ind = n-1; ind >= 0; ind--)
    //     {
    //         //0 means we need to buy or notbuy
    //         dp[ind][0] = Math.max(dp[ind+1][1] - values[ind], dp[ind+1][0]);

    //         //1 means we need to sell or notsell
    //         dp[ind][1] = Math.max(values[ind] + dp[ind+1][0], dp[ind+1][1]);
    //     }

    //     return dp[0][0];

    // }


    //SPACE OPTIMIZATION
    public static long getMaximumProfit (int n, long[] values) 
    {
        
        //base case
        long prev1 = 0;
        long prev2 = 0;
        long curr1 = 0;
        long curr2 = 0;

        for(int ind = n-1; ind >= 0; ind--)
        {
            //0 represents need to buy a new stock
            curr1 = Math.max(prev2 - values[ind], prev1);
    
            //1 represents already a stock is bought
            curr2 = Math.max(values[ind] + curr1, curr2);
        }

        return curr1;

    }
}