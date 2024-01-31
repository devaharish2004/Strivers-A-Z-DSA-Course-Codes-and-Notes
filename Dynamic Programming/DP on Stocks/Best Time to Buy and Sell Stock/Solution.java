class Solution {
    public int maxProfit(int[] prices) {
        int mini = Integer.MAX_VALUE;
        int maxprofit = 0;
        for(int i = 0; i < prices.length; i++)
        {
            int cost = prices[i] - mini;
            maxprofit = Math.max(maxprofit, cost);
            mini = Math.min(mini, prices[i]);
        }

        return maxprofit;
    }
}

//for all stocks problem, do till space optimization - MUST