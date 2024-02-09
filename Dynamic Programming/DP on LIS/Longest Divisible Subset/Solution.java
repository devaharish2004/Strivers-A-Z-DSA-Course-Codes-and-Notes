import java.util.*;

public class Solution {
    public static List< Integer > divisibleSet(int nums[]) 
    {
        int n= nums.length;
        // Write your code here.
        int[] dp = new int[n];
        
        Arrays.fill(dp, 1);
        
        int[] hash = new int[n];
        
        int ans = Integer.MIN_VALUE;
        int max_index = -1;

        Arrays.sort(nums);
        
        //O(n^2)
        for(int ind = 0; ind <= n-1; ind++)
        {
            
            hash[ind] = ind;
            
            for(int prev = 0; prev < ind; prev++)
            {
                
                //if the number is in increasing order and the subsequence length is maximum
                
                if(nums[ind]%nums[prev] == 0 && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    
                    hash[ind] = prev; 
                }
            }
            
            if(dp[ind] > ans)
            {
                ans = dp[ind];
                max_index = ind;
            }
        }
        
        //O(n) for backtracking
        List<Integer> list = new ArrayList<Integer>();
        list.add(nums[max_index]);
        
        while(hash[max_index] != max_index)
        {
            max_index = hash[max_index];
            list.add(nums[max_index]);
        }
        
        Collections.reverse(list);
        
        return list;
    }
}

/*KEY POINTS TO BE NOTED FOR THIS PROBLEM
 * This problem is solved based on the algorithmic approach for LIS
 * Subset means you can pick it like a subsequence but the order is not necessary
 * We sort the array first for two reasons :
 * 1 : To check the divisibility of a number for all the elements in the answer array optimally
 * 2 : Since the question asks for a subset and not a subsequence, we can sort it to reduce the complexity of the problem.
 * The algorithm for checking divisibility optimally works only because the given array has been sorted.
 * Instead of checking if the current number forms an increasing subsequence, we can check if the current number is divisible with the previous element.
 * As the array is sorted, we can be sure that checking the above one condition is enough instead of checking for all the elements of the ans array.
 * TC : O(N^2) + O(N)
 * SC : O(2N) ~ O(N)
 */