import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;

public class Solution 
{
    public static List< Integer > printingLongestIncreasingSubsequence(int []arr, int x) 
    {
        // Write Your Code Here
        int dp[] = new int[x];
        Arrays.fill(dp, 1);
        int hash[] = new int[x];
        int ans = 1;
        int index = 0;
        for(int i = 0; i < x; i++)
        {
            hash[i] = i; //initialization of values
            for(int prev = 0; prev < i; prev++)
            {
                if(arr[prev] < arr[i] && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
                
            }

            if(dp[i] > ans)
            {
                ans = dp[i];
                index = i;
            }
        }

        //ans stores the longest increasing subsequence
        List<Integer> list = new ArrayList<>();
        list.add(arr[index]);

        while(hash[index] != index)
        {
            index = hash[index];
            list.add(arr[index]);
        }

        Collections.reverse(list);

        return list;

        
    }
}