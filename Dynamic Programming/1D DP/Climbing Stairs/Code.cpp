#include <bits/stdc++.h> 

int solve(int nStairs, vector<long long>&dp, int mod)
{
    if(nStairs == 0 || nStairs == 1) return 1;
    if(dp[nStairs] != -1)
    {
        return dp[nStairs];
    }
    int f1 = solve(nStairs-1,dp,mod);
    int f2 = solve(nStairs-2,dp,mod);
    return dp[nStairs] = (f1+f2)%mod;

}

int countDistinctWays(int nStairs) 
{
    //  Write your code here.
    int mod = 1e9+7;
    vector<long long> dp(nStairs+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    return solve(nStairs,dp,mod);
}