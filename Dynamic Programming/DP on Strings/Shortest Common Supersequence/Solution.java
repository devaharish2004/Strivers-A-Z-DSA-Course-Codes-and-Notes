import java.util.* ;
import java.io.*; 
public class Solution {
    public static String shortestSupersequence(String a, String b) {
        // Write your code here..
        int n = a.length();
        int m = b.length();

        // write the dp
        int [][] dp = new int[n+1][m+1];

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a.charAt(i-1) == b.charAt(j-1))
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //string
        String ans = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0)
        {
            if(a.charAt(i-1) == b.charAt(j-1)) //matching characters should be taken once
            {
                ans += a.charAt(i-1);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) //up
            {
                ans += a.charAt(i-1);
                i--;
            }
            else //left
            {
                ans += b.charAt(j-1);
                j--;
            }
        }

        //to avoid missing parts of strings
        while(i > 0) 
        {
            ans += a.charAt(i-1);
            i--;
        }
        while(j > 0)
        {
            ans += b.charAt(j-1);
            j--;
        }

        String ans2 = new StringBuilder(ans).reverse().toString();

        return ans2;

        
    }

}