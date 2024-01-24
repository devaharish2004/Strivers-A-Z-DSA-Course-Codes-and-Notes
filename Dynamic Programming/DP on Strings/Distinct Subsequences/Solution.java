//ublic class Solution {
    //MEMOIZATION
    // static int solve(int ind1, int ind2, String str, String sub, int[][] dp)
    // {
    //     int mod = (int)(Math.pow(10,9) + 7);

    //     if(ind2 == 0) //means that the sub is completely exhausted
    //     {
    //         return dp[ind1][ind2] = 1;
    //     }

    //     if(ind1 <= 0)
    //     {
    //         return dp[ind1][ind2] = 0;
    //     }

    //     if(dp[ind1][ind2] != -1)
    //     {
    //         return dp[ind1][ind2];
    //     }

    //     int notPick = solve(ind1-1, ind2, str, sub, dp)%mod;

    //     int pick = 0;

    //     if(str.charAt(ind1 - 1) == sub.charAt(ind2 - 1)) //if there's a match
    //     {
    //         pick = solve(ind1-1, ind2-1, str, sub, dp)%mod;  //picking the letter
    //     }

    //     return dp[ind1][ind2] = (pick + notPick)%mod;
    // }
    // public static int distinctSubsequences(String str, String sub) {
    //     // Write your code here.
    //     int n = str.length();
    //     int m = sub.length();
    //     int[][] dp = new int[n+1][m+1];
    //     for(int i = 0; i <= n; i++)
    //     {
    //         for(int j = 0; j <= m; j++)
    //         {
    //             dp[i][j] = -1;
    //         }
    //     }
    //     return solve(n, m, str, sub, dp);
    // }

    //TABULATION
//     public static int distinctSubsequences(String str, String sub) {
//         // Write your code here.
//         int n = str.length();
//         int m = sub.length();
//         int[][] dp = new int[n+1][m+1];

//         int mod = (int)(Math.pow(10,9) + 7);

//         for(int i = 0; i <= n; i++)
//         {
//             dp[i][0] = 1;
//         }

//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 int notPick = dp[i-1][j];
//                 int pick = 0;
//                 if(str.charAt(i-1) == sub.charAt(j-1))
//                 {
//                     pick = dp[i-1][j-1];
//                 }

//                 dp[i][j] = (pick + notPick)%mod;
//             }
//         }
        
//         return dp[n][m];
//     }
// }

//SPACE OPTIMIZATION - 1D 
public class Solution {
    static int prime = (int) (Math.pow(10, 9) + 7);

    // Function to calculate the count of distinct subsequences of s1 equal to s2
    static int subsequenceCounting(String s1, String s2, int n, int m) {
        // Create an array to store the counts of subsequences
        int[] prev = new int[m + 1];

        // Initialize the first element to 1 because there's one empty subsequence in any string.
        prev[0] = 1;

        // Fill the prev array using a bottom-up approach
        for (int i = 1; i < n + 1; i++) {
            for (int j = m; j >= 1; j--) { // Reverse direction for updating

                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    // If the characters match, we can either include this character in the subsequence
                    // or exclude it. So, we add the counts from both possibilities.
                    prev[j] = (prev[j - 1] + prev[j]) % prime;
                } else {
                    // If the characters don't match, we can only exclude this character.
                    prev[j] = prev[j]; // This statement is not necessary, as it doesn't change the value.
                }
            }
        }

        return prev[m];
    }

    public static void main(String args[]) {
        String s1 = "babgbag";
        String s2 = "bag";

        System.out.println("The Count of Distinct Subsequences is " +
                subsequenceCounting(s1, s2, s1.length(), s2.length()));
    }
}