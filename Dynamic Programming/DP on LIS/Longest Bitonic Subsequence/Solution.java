import java.util.*;

public class Solution {
    public static int longestBitonicSequence(int[] arr, int n) {
        // Write your code here.
        int[] dp1 = new int[n]; //checking from the left
        int[] dp2 = new int[n]; //checking from the right
        
        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);

        //from the left side
        for(int ind = 0; ind < n; ind++)
        {
            for(int prev = 0; prev < ind; prev++)
            {
                if(arr[prev] < arr[ind] && 1 + dp1[prev] > dp1[ind])
                {
                    dp1[ind] = 1 + dp1[prev];
                }
            }
        }

        //from the right side
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int prev = n-1; prev > ind; prev--)
            {
                if(arr[prev] < arr[ind] && 1 + dp2[prev] > dp2[ind])
                {
                    dp2[ind] = 1 + dp2[prev];
                }
            }
        }

        //find the bitonic sequence by adding
        int ans = 1;
        for(int ind = 0; ind < n; ind++)
        {
            int sum = dp1[ind] + dp2[ind] - 1; //-1 for taking the common value
            if(sum > ans)
            {
                ans = sum;
            }
        }

        return ans;
    }
}
