class Solution {
public:
    int helper(int index, int sum, vector<int>&coins,vector<vector<int>>&dp){
        if(index==0){
            if(sum%coins[0]!=0) return 1e9;
            return sum/coins[0];
        }

        if(dp[index][sum]!=-1) return dp[index][sum];

        int notPick = helper(index - 1, sum, coins,dp);
        int pick = 1e9;
        if(coins[index]<=sum) pick = 1 + helper(index, sum - coins[index], coins,dp);
        return dp[index][sum] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<vector<int>>dp(n, vector<int>(amount+1,0));
        vector<int>prev(amount+1,0), curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]!=0) prev[i] = 1e9;
            else prev[i] = i/coins[0];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notPick = prev[j];
                int pick = 1e9;
                if(coins[i]<=j) pick = 1 + curr[j - coins[i]];
                curr[j] = min(pick, notPick);
            }
            prev=curr;
        }


        return prev[amount]==1e9?-1:prev[amount];
        
    }
};
