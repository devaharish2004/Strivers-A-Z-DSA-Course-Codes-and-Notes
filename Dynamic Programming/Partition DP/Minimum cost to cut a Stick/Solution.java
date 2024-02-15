/*
 * WE CAN CHANGE THE ORDER OF THE ARRAY AS WE WANTED, BUT IN ORDER TO CHECK SUBPROBLEMS INDEPENDENTLY, WE MUST SORT THE ARRAY FIRST
 * LET'S SAY WE HAVE 1, 2, 3, 4, 5
 * WE CAN START FROM ANY CUT GIVEN IN THE ARRAY
 * BUT IF WE ARE GIVEN 1, 2, 4, 5, 3
 * WE CAN'T SOLVE THEM SEPARATELY AS ONE CUT WILL BE DEPENDENT ON THE OTHER CUT SEQUENCE.
 * SOLVE(START, END) REPRESENTS THE MIN COST TO CUT THE STICK BY USING THE CUT POSITIONS FROM START TO END
 */

import java.util.*;

 class Solution 
{
    //MEMOIZATION
    // int solve(int start, int end, ArrayList<Integer> arr, int n, int[][] dp)
    // {
    //     if(start > end) return 0; 

    //     if(dp[start][end] != -1)
    //     {
    //         return dp[start][end];
    //     }

    //     int mini = Integer.MAX_VALUE;

    //     for(int ind = start; ind <= end; ind++)
    //     {
    //         int cost = arr.get(end+1) - arr.get(start-1) + 
    //                     solve(start, ind-1, arr, n, dp) + 
    //                     solve(ind+1, end, arr, n, dp);
                        
    //         mini = Math.min(cost, mini);
    //     }

    //     return dp[start][end] = mini;

    // }
    // public int minCost(int n, int[] cuts) 
    // {
    //     ArrayList<Integer> arr = new ArrayList<>();
    //     for(int el : cuts)
    //     {
    //         arr.add(el);
    //     }
    //     arr.add(n);
    //     arr.add(0);
    //     Collections.sort(arr);
    //     int c = cuts.length;
    //     int[][] dp = new int[c+1][c+1]; //start and end can go from 1 to cuts.length
    //     for(int[] rows : dp)
    //     {
    //         Arrays.fill(rows, -1);
    //     }
    //     return solve(1, arr.size()-2, arr, n, dp);
        
    // }

    // TABULATION
    public int minCost(int n, int[] cuts) 
    {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int el : cuts)
        {
            arr.add(el);
        }
        arr.add(n);
        arr.add(0);
        Collections.sort(arr);

        int c = cuts.length;
        int[][] dp = new int[c+2][c+2]; //start and end can go from 1 to cuts.length - also when start = c, ind when starting from c will consider ind+1 => c+1 also. So for safety we have included c+2 also.
        
        for(int start = c; start >= 1; start--)
        {
            for(int end = 1; end <= c; end++)
            {
                if(start > end) continue;
                int mini = Integer.MAX_VALUE;
                for(int ind = start; ind <= end; ind++)
                {
                    int cost = arr.get(end+1) - arr.get(start-1) + dp[start][ind-1] + dp[ind+1][end];
                    mini = Math.min(mini, cost);
                }
                dp[start][end] = mini;
            }
        }

        return dp[1][c];
        
    }
}