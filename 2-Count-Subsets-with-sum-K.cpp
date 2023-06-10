#include <bits/stdc++.h> 
int helper(int index, int sum, vector<int>&num, vector<vector<int>>&dp){
    // if(sum==0) return 1;
    if(index==0){
        if(sum==0 and num[0]==0) return 2;
        if(sum==0 or num[0]==sum) return 1;
        return 0;
    }
    if(dp[index][sum]!=-1) return dp[index][sum];
    int pick = 0, notPick = 0;
    if (num[index] <= sum) {
      pick = helper(index - 1, sum - num[index], num,dp);
      notPick = helper(index - 1, sum, num,dp);
    } else
      notPick = helper(index - 1, sum, num,dp);
    return dp[index][sum] = pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int numZeroes = 0;
    for(auto it:num) if(it==0) numZeroes++;
    vector<vector<int>>dp(num.size()+1, vector<int>(tar+1,-1));
    int val = pow(2, numZeroes);

    return helper(num.size()-1, tar, num,dp);
    
}
