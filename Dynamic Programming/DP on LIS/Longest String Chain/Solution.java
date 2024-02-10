import java.util.Arrays;
import java.util.Comparator;

//LEETCODE 
class Solution 
{
    public boolean comp (String a, String b)
    {
        if(a.length() != b.length() + 1) return false;
        int first = 0;
        int second = 0;
        while(first < a.length())
        {
            if(second < b.length() && a.charAt(first) == b.charAt(second))
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if(first == a.length() && second == b.length())
        {
            return true;
        }

        return false;
    }
    public int longestStrChain(String[] words) 
    {
        int n = words.length;

        Arrays.sort(words, new compareObj());

        int[] dp = new int[n];

        Arrays.fill(dp, 1);

        int ans = 1;

        for(int ind = 0; ind < n; ind++)
        {
            for(int prev = 0; prev < ind; prev++)
            {
                if(comp(words[ind], words[prev]) && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                }
            }

            if(dp[ind] > ans)
            {
                ans = dp[ind];
            }
        }

        return ans;

    }
}

//another way of implementing own logic in the sort function

class compareObj implements Comparator<String> 
{
    @Override
    public int compare(String a, String b)
    {
        return a.length() - b.length();
        // if the return value
        //negative - a comes before b
        //0 - a and b are equal
        // positive - a comes after b
    }

}

//CODING NINJAS
//import java.util.*;
// public class Solution 
// {

//     static Comparator<String> compare = (s1,s2) -> s1.length() - s2.length();  //lambda expression for creating a new object of comparator and implementing the sorting logic

//     public static boolean comp (String a, String b)
//     {
//         //since x will be larger as we sorted the array
//         if(a.length() != b.length()+1) return false;

//         int first = 0;
//         int second = 0;

//         while(first < a.length())
//         {

//             if(second < b.length() && a.charAt(first) == b.charAt(second))
//             {
//                 first++;
//                 second++;
//             }
//             else
//             {
//                 first++;
//             }
//         }

//         //if both the pointers reach the end finally
//         if( (first == a.length() && second == b.length()) )
//         { 
//             return true;
//         }

//         return false;
//     }
//     public static int longestStrChain(String[] arr) 
//     {
//         // Write your code here.
//         int n = arr.length;

//         Arrays.sort(arr, compare); //since we can include subset also


//         int[] dp = new int[n];

//         Arrays.fill(dp, 1);

//         int ans = 1;

//         for(int ind = 0; ind < n; ind++)
//         {
//             for(int prev = 0; prev < ind; prev++)
//             {
//                 if(comp(arr[ind], arr[prev]) && dp[prev]+1 > dp[ind])
//                 {
//                     dp[ind] = dp[prev] + 1;
//                 }
//             }
//             ans = Math.max(ans, dp[ind]);
//         }

//         return ans;
//     }
// }
