// import java.util.Arrays;
//MEMOIZATION
// class StockProfit {
//     static int getAns(int[] Arr, int n, int ind, int buy, int cap, int[][][] dp) {
//         // Base case: If we have processed all stocks or have no capital left, return 0 profit
//         if (ind == n || cap == 0)
//             return 0;

//         // If the result for this state is already calculated, return it
//         if (dp[ind][buy][cap] != -1)
//             return dp[ind][buy][cap];

//         int profit;

//         if (buy == 0) { // We can buy the stock
//             profit = Math.max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
//                     -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
//         }

//         if (buy == 1) { // We can sell the stock
//             profit = Math.max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
//                     Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
//         }

//         // Store the calculated profit in the dp array and return it
//         return dp[ind][buy][cap] = profit;
//     }

//     static int maxProfit(int[] prices) {
//         int n = prices.length;

//         // Creating a 3D dp array of size [n][2][3]
//         int[][][] dp = new int[n][2][3];

//         // Initialize the dp array with -1
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < 2; j++) {
//                 Arrays.fill(dp[i][j], -1);
//             }
//         }

//         // Calculate and return the maximum profit
//         return getAns(prices, n, 0, 0, 2, dp);
//     }

//     public static void main(String[] args) {
//         int[] prices = {3, 3, 5, 0, 0, 3, 1, 4};
//         int n = prices.length;

//         // Calculate and print the maximum profit
//         System.out.println("The maximum profit that can be generated is " + maxProfit(prices));
//     }
// }

//TABULATION
// import java.util.Arrays;

// class StockProfit {
//     static int maxProfit(int[] prices) {
//         int n = prices.length;

//         // Creating a 3D dp array of size [n+1][2][3] initialized to 0
//         int[][][] dp = new int[n + 1][2][3];

//         // Loop through the dp array, starting from the second last stock (ind=n-1)
//         for (int ind = n - 1; ind >= 0; ind--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int cap = 1; cap <= 2; cap++) {

//                     if (buy == 0) { // We can buy the stock
//                         dp[ind][buy][cap] = Math.max(0 + dp[ind + 1][0][cap],
//                                 -prices[ind] + dp[ind + 1][1][cap]);
//                     }

//                     if (buy == 1) { // We can sell the stock
//                         dp[ind][buy][cap] = Math.max(0 + dp[ind + 1][1][cap],
//                                 prices[ind] + dp[ind + 1][0][cap - 1]);
//                     }
//                 }
//             }
//         }

//         // The maximum profit with 2 transactions is stored in dp[0][0][2]
//         return dp[0][0][2];
//     }

//     public static void main(String[] args) {
//         int[] prices = {3, 3, 5, 0, 0, 3, 1, 4};
//         int n = prices.length;

//         // Calculate and print the maximum profit
//         System.out.println("The maximum profit that can be generated is " + maxProfit(prices));
//     }
// }

//SPACE OPTIMIZATION
class StockProfit {
    static int maxProfit(int[] prices) {
        int n = prices.length;

        // Create a 2D array 'ahead' and 'cur' to store profit values
        int[][] ahead = new int[2][3];
        int[][] cur = new int[2][3];

        // Loop through the prices array, starting from the second last stock (ind=n-1)
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 0) { // We can buy the stock
                        cur[buy][cap] = Math.max(0 + ahead[0][cap],
                                -prices[ind] + ahead[1][cap]);
                    }

                    if (buy == 1) { // We can sell the stock
                        cur[buy][cap] = Math.max(0 + ahead[1][cap],
                                prices[ind] + ahead[0][cap - 1]);
                    }
                }
            }

            // Update 'ahead' with the values in 'cur'
            for (int i = 0; i < 2; i++) {
                for (int j = 1; j < 3; j++) {
                    ahead[i][j] = cur[i][j];
                }
            }
        }

        // The maximum profit with 2 transactions is stored in ahead[0][2]
        return ahead[0][2];
    }

    public static void main(String[] args) {
        int[] prices = {3, 3, 5, 0, 0, 3, 1, 4};

        // Calculate and print the maximum profit
        System.out.println("The maximum profit that can be generated is " + maxProfit(prices));
    }
}

//There is another way to solve this problem using N X 4 dp array.
//We keep the transaction number to solve.
// A transaction means buying or selling a stock.
//If maximum two stocks can be bought and sold, then the maximum transactions would be 4.
//Using the previous problem, we can solve this problem.




